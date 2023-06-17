#include <iostream>
#include "egil_stack.h"

int main() {
    stack<int> stack_a(1);
    try {
        stack_a.pop();
    }
   
    catch (const std::out_of_range& currentError) {
        std::cerr << "out: ";
        std::cerr << currentError.what() << std::endl;
    }
   
    try {
        stack_a.top();
    }
    catch (const std::logic_error currentError) {
        std::cerr << "logic: ";
        std::cerr << currentError.what() << std::endl;
    }

    try {
        stack_a.push(5);
    }
    catch (const std::overflow_error& currentError) {
        std::cerr << "overflow: ";
        std::cerr << currentError.what() << std::endl;
    }

    try {
        stack<int> stack_b(10000000000000);
    }
    catch (const std::bad_alloc& currentError) {
        std::cerr << "alloc: ";
        std::cerr << currentError.what() << std::endl;
    }

    try {
        std::cout << stack_a.pop() << std::endl;
    }

    catch (const std::out_of_range& currentError) {
        std::cerr << "out: ";
        std::cerr << currentError.what() << std::endl;
    }

    try {
        stack_a.push(5);
    }
    catch (const std::overflow_error& currentError) {
        std::cerr << "overflow: ";
        std::cerr << currentError.what() << std::endl;
    }
    stack_a.size();

    try {
        stack_a.push(5);
    }
    catch (const std::overflow_error& currentError) {
        std::cerr << "overflow: ";
        std::cerr << currentError.what() << std::endl;
    }
   
    
   

    return 0;

 
}