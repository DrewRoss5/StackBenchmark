#ifndef LINK_STACK_H
#define LINK_STACK_H

#include <cstddef>
#include <stdexcept>

template <typename T>
struct Node{
    T val;
    Node<T>* prev {nullptr};
    Node(const T& val);
};

// constructor for the Node struct
template <typename T>
Node<T>::Node(const T& val){
    this->val = val;
}

template <typename T>
class LinkedStack{
    public:
        LinkedStack();
        ~LinkedStack();
        T top();
        void pop();
        void push(const T& val);
        bool empty() {return this->tail == nullptr;}
    private:
        Node<T>* tail;

};

// constructor for the stack
template <typename T>
LinkedStack<T>::LinkedStack(){
    this->tail = nullptr;
}

// deconstructor for the stack, deletes each node individually
template <typename T>
LinkedStack<T>::~LinkedStack(){
    Node<T>* curr = this->tail;
    while (curr){
        Node<T>* tmp = curr->prev;
        delete curr;
        curr = tmp;
    }
}

// returns the top value of the stack
template <typename T>
T LinkedStack<T>::top(){
    if (!this->tail)
        throw std::runtime_error("Cannot get a value from an empty stack");
    return this->tail->val;
}

// removes the top value of the stack
template <typename T>
void LinkedStack<T>::pop(){
    if (!this->tail)
        throw std::runtime_error("Cannot pop a value from an empty stack");
    Node<T>* tmp = this->tail;
    this->tail = tmp->prev;
    delete tmp;
}

// pushes a new value onto the stack
template <typename T>
void LinkedStack<T>::push(const T& val){
    Node<T>* new_node = new Node<T>(val);
    if (this->tail)
        new_node->prev = this->tail;
    this->tail = new_node;
}

#endif