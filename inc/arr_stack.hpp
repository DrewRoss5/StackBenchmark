#ifndef ARR_STACK_H
#define ARR_STACK_H

#include <cstddef>
#include <stdexcept>
#include <cstring>

template <typename T>
class ArrayStack{
    public:
        ArrayStack(size_t init_size = 32);
        ~ArrayStack();
        T top();
        void pop();
        void push(const T& val);
    private:
        size_t curr_size {0};
        size_t capacity {0};
        T* arr;
};

// constructor for the stack
template <typename T>
ArrayStack<T>::ArrayStack(size_t init_size){
    this->arr = new T[init_size];
    this->capacity = init_size;
}

// destructor for the stack
template <typename T>
ArrayStack<T>::~ArrayStack(){
    delete[] this->arr;
    this->arr = nullptr;
}

// returns the top value of the stack
template <typename T>
T ArrayStack<T>::top(){
    if (this->curr_size == 0)
        throw std::runtime_error("Cannot get a value from an empty stack");
    return this->arr[curr_size - 1];
}

// pops the first value of the stack
template <typename T>
void ArrayStack<T>::pop(){
    if (this->curr_size == 0)
        throw std::runtime_error("Cannot get a value from an empty stack");
    this->curr_size--;
}

// push the given value to the stack
template <typename T>
void ArrayStack<T>::push(const T& val){
    // check if we've reached the maximum size of the array and need to reallocate
    if (this->curr_size == this->capacity){
        this->capacity *= 2;
        T new_arr = new T[this->capacity];
        std::memcpy(new_arr, this->arr, sizeof(T) * this->curr_size);       
    }
    // push the value
    this->arr[this->curr_size] = val;
    this->curr_size++;
}

#endif