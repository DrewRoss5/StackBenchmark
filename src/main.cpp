#include <iostream>
#include <stdio.h>
#include <chrono>

#include "../inc/arr_stack.hpp"
#include "../inc/list_stack.hpp"

int main(int argc, char** argv){
    if (argc != 2){
        std::cerr << "\033[31mError:\033[0m This program accepts exactly one argument" << std::endl;
        return 1;
    }
    // determine the number of elements to generate
    int num_elems;
    try{
        num_elems = std::stoi(argv[1]);
    }
    catch (...){
        std::cerr << "\033[31mError:\033[0m Invalid number of elements" << std::endl;
    }
    // benchmark the array based stack
    std::cout << "Benchmarking Array-Based Stack:\n-------------------------------" << std::endl;
    auto t1 = std::chrono::high_resolution_clock::now();
    ArrayStack<int> arr_stack;
    for (int i = 0; i < num_elems; i++)
        arr_stack.push(i);
    auto t2 = std::chrono::high_resolution_clock::now();
    auto push_time = std::chrono::duration<double, std::milli>(t2 - t1);
    std::cout << "Time to push " << num_elems << " elements: " << push_time.count() << "ms" << std::endl;
    t1 = std::chrono::high_resolution_clock::now();
    while (!arr_stack.empty()){
        //printf("%d\n", arr_stack.top()); // printf is used to minimize run times
        arr_stack.pop();
    }
    t2 = std::chrono::high_resolution_clock::now();
    auto pop_time = std::chrono::duration<double, std::milli>(t2 - t1);
    std::cout << "Time to pop " << num_elems << " elements: " << pop_time.count() << "ms" << std::endl;
    auto arr_time = push_time + pop_time;
    // benchmark the list based stack
    std::cout << "-------------------------------\nBenchmarking List-Based Stack:\n-------------------------------" << std::endl;
    t1 = std::chrono::high_resolution_clock::now();
    LinkedStack<int> linked_stack;
    for (int i = 0; i < num_elems; i++)
        linked_stack.push(i);
    t2 = std::chrono::high_resolution_clock::now();
    push_time = std::chrono::duration<double, std::milli>(t2 - t1);
    std::cout << "Time to push " << num_elems << " elements: " << push_time.count() << "ms" << std::endl;
    t1 = std::chrono::high_resolution_clock::now();
    while (!linked_stack.empty()){
        //printf("%d\n", linked_stack.top()); // printf is used to minimize run times
        linked_stack.pop();
    }
    t2 = std::chrono::high_resolution_clock::now();
    pop_time = std::chrono::duration<double, std::milli>(t2 - t1);
    std::cout << "Time to pop " << num_elems << " elements: " << pop_time.count() << "ms" << std::endl;
    auto list_time = pop_time + push_time;
    // display the results of the benchmark
    std::cout << "-------------------------------\nResults:\n------------------------------\n";
    std::cout << "Array-based time: " << arr_time.count() << "ms\n" << "List-based time: " << list_time.count() << "ms" << std::endl;
    // determine which implementation is faster and display it to the user
    
    if (arr_time < list_time){
        double margin = ((list_time - arr_time) / list_time) * 100;
        std::cout << "The array-based stack was  " << margin << "% faster than the list-based stack." << std::endl;
    }
    else{
        double margin = ((arr_time - list_time) / arr_time) * 100;
        std::cout << "The list-based stack was  " << margin << "% faster than the array-based stack." << std::endl;
    }
    return 0;

}
