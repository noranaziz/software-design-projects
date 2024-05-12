// test cases

// include all header files
#include "Base_Array.h"
#include "Array.h"
#include "Fixed_Array.h"
#include "Stack.h"
#include "Queue.h"

#include <iostream>

// main
int main()
{
    // === BASE ARRAY ===
    // base array default ctor
    std::cout << "testing base array default ctor:\n";
    Base_Array<int> int_array;
    std::cout << "\n";

    // base array length ctor
    std::cout << "\ntesting base array length ctor:\n";
    Base_Array<int> int_array_length(5);
    std::cout << "\n";

    // base array length & fill ctor
    std::cout << "\ntesting base array length and fill ctor:\n";
    Base_Array<char> char_array_fill(3, 'A');
    for(size_t i = 0; i < char_array_fill.size(); i++) {
        std::cout << char_array_fill[i] << " ";
    }
    std::cout << "\n";

    // base array copy ctor
    std::cout << "\ntesting base array copy ctor:\n";
    Base_Array<char> char_array_copy(char_array_fill);
    for(size_t i = 0; i < char_array_copy.size(); i++) {
        std::cout << char_array_copy[i] << " ";
    }
    std::cout << "\n";

    // base array assignment operator
    std::cout << "\ntesting base array assignment operator:\n";
    Base_Array<char> char_array_assign;
    char_array_assign = char_array_fill;
    for(size_t i = 0; i < char_array_assign.size(); i++) {
        std::cout << char_array_assign[i] << " ";
    }
    std::cout << "\n";

    // base array subscript operator
    std::cout << "\ntesting base array subscript operator:\n";
    int_array_length[0] = 1;
    int_array_length[1] = 2;
    int_array_length[2] = 3;
    int_array_length[3] = 4;
    int_array_length[4] = 5;
    for(size_t i = 0; i < int_array_length.size(); i++) {
        std::cout << int_array_length[i] << " ";
    }
    std::cout << "\n";

    // base array get method
    std::cout << "\ntesting base array get method:\n";
    std::cout << "int_array_length index 2: " << int_array_length.get(2);
    std::cout << "\n";

    // base array set method
    std::cout << "\ntesting base array set method:\n";
    int_array_length.set(0, 10);
    std::cout << "\n";

    // base array find method
    std::cout << "\ntesting base array find method:\n";
    int found = int_array_length.find(3);
    int found2 = char_array_fill.find('A');
    int found3 = int_array_length.find(5, 2);
    std::cout << "found 3 at index " << found << "\n";
    std::cout << "found A at index " << found2 << "\n";
    std::cout << "found 5 at index " << found3 << "\n";
    std::cout << "\n";

    // base array equality operator
    std::cout << "\ntesting base array equality operator:\n";
    bool equal = (int_array == int_array_length);
    std::cout << "int_array == int_array_length? " << equal << "\n";
    std::cout << "\n";

    // base array inequality operator
    std::cout << "\ntesting base array inequality operator:\n";
    bool not_equal = (char_array_copy != char_array_assign);
    std::cout << "char_array_copy != char_array_assign? " << not_equal << "\n";
    std::cout << "\n";

    // base array fill method
    std::cout << "\ntesting base array fill method:\n";
    char_array_copy.fill('Z');
    for(size_t i = 0; i < char_array_copy.size(); i++) {
        std::cout << char_array_copy[i] << " ";
    }
    std::cout << "\n";

    // base array reverse method
    std::cout << "\ntesting base array reverse method:\n";
    int_array_length.reverse();
    for(size_t i = 0; i < int_array_length.size(); i++) {
        std::cout << int_array_length[i] << " ";
    }
    std::cout << "\n";

    // base array slice method
    std::cout << "\ntesting base array slice method:\n";
    Base_Array<int> slice = int_array_length.slice(1, 4);
    for(size_t i = 0; i < slice.size(); i++) {
        std::cout << slice[i] << " ";
    }
    std::cout << "\n";


    // === ARRAY ===
    // array default ctor
    std::cout << "testing array default ctor:\n";
    Array<int> int_array_default;
    std::cout << "\n";

    // array length ctor
    std::cout << "\ntesting array length ctor:\n";
    Array<double> double_array_length(5);
    std::cout << "\n";

    // array length & fill ctor
    std::cout << "\ntesting array length and fill ctor:\n";
    Array<char> char_arr_fill(3, 'A');
    for(size_t i = 0; i < char_arr_fill.size(); i++) {
        std::cout << char_arr_fill[i] << " ";
    }
    std::cout << "\n";

    // array copy ctor
    std::cout << "\ntesting array copy ctor:\n";
    Array<char> char_arr_copy(char_arr_fill);
    for(size_t i = 0; i < char_arr_copy.size(); i++) {
        std::cout << char_arr_copy[i] << " ";
    }
    std::cout << "\n";

    // array assignment operator
    std::cout << "\ntesting array assignment operator:\n";
    Array<char> char_arr_assign;
    char_arr_assign = char_arr_fill;
    for(size_t i = 0; i < char_arr_assign.size(); i++) {
        std::cout << char_arr_assign[i] << " ";
    }
    std::cout << "\n";

    // array resize method
    std::cout << "\ntesting array resize method:\n";
    std::cout << "size 3 -> size 5\n";
    char_arr_fill.resize(5);
    char_arr_fill[3] = 'B';
    char_arr_fill[4] = 'C';
    for(size_t i = 0; i < char_arr_fill.size(); i++) {
        std::cout << char_arr_fill[i] << " ";
    }
    std::cout << "\n";
    std::cout << "current size: " << char_arr_fill.size() << "\n";
    std::cout << "max size: " << char_arr_fill.max_size() << "\n";
    std::cout << "\n";
    std::cout << "size 5 -> size 2\n";
    char_arr_fill.resize(2);
    for(size_t i = 0; i < char_arr_fill.size(); i++) {
        std::cout << char_arr_fill[i] << " ";
    }
    std::cout << "\n";
    std::cout << "current size: " << char_arr_fill.size() << "\n";
    std::cout << "max size: " << char_arr_fill.max_size() << "\n";
    std::cout << "\n";

    // array shrink method
    std::cout << "\ntesting shrink method:\n";
    char_arr_fill.shrink();
    std::cout << "current size: " << char_arr_fill.size() << "\n";
    std::cout << "max size: " << char_arr_fill.max_size() << "\n";
    std::cout << "\n";


    // === FIXED ARRAY ===
    // fixed array default ctor
    std::cout << "\ntesting fixed array default ctor:\n";
    Fixed_Array<int, 5> int_fixed_array;
    std::cout << "\n";

    // fixed array copy ctor
    std::cout << "\ntesting fixed array copy ctor:\n";
    Fixed_Array<int, 5> int_fixed_array_copy(int_fixed_array);
    for(size_t i = 0; i < int_fixed_array_copy.size(); i++) {
        std::cout << int_fixed_array_copy[i] << " ";
    }
    std::cout << "\n";

    // fixed array fill ctor
    std::cout << "\ntesting fixed array fill ctor:\n";
    Fixed_Array<char, 4> char_fixed_array_fill('N');
    for(size_t i = 0; i < char_fixed_array_fill.size(); i++) {
        std::cout << char_fixed_array_fill[i] << " ";
    }
    std::cout << "\n";

    // fixed array assignment operator
    std::cout << "\ntesting fixed array assignment operator:\n";
    Fixed_Array<char, 4> char_fixed_array_assign;
    char_fixed_array_assign = char_fixed_array_fill;
    for(size_t i = 0; i < char_fixed_array_assign.size(); i++) {
        std::cout << char_fixed_array_assign[i] << " ";
    }
    std::cout << "\n";


    // === STACK ===
    // stack default ctor
    std::cout << "\ntesting stack default ctor:\n";
    Stack<int> int_stack;
    std::cout << "\n";

    // stack copy ctor
    std::cout << "\ntesting stack copy ctor:\n";
    Stack<int> int_stack_copy(int_stack);
    std::cout << "size of stack: " << int_stack_copy.size() << "\n";
    std::cout << "\n";

    // stack push method
    std::cout << "\ntesting stack push method:\n";
    for(size_t i = 0; i < 5; i++) {
        int_stack_copy.push(i);
        std::cout << int_stack_copy.top() << "\n";
    }
    std::cout << "\n";
    std::cout << "size of stack: " << int_stack_copy.size() << "\n";
    std::cout << "\n";

    // stack pop method
    std::cout << "\ntesting stack pop method:\n";
    for(size_t i = 0; i < 2; i++) {
        std::cout << int_stack_copy.top() << "\n";
        int_stack_copy.pop();
    }
    std::cout << "\n";
    std::cout << "size of stack: " << int_stack_copy.size() << "\n";
    std::cout << "\n";

    // stack assignment operator
    std::cout << "\ntesting stack assignment operator:\n";
    Stack<int> int_stack_assign;
    int_stack_assign = int_stack_copy;
    for(size_t i = 0; i < 2; i++) {
        std::cout << int_stack_assign.top() << "\n";
        int_stack_assign.pop();
    }
    std::cout << "\n";
    std::cout << "size of stack: " << int_stack_assign.size() << "\n";
    std::cout << "\n";

    // stack clear method
    std::cout << "\ntesting stack clear method:\n";
    int_stack_assign.clear();
    std::cout << "size of stack: " << int_stack_assign.size() << "\n";


    // === QUEUE ===
    // queue default ctor
    std::cout << "\ntesting queue default ctor:\n";
    Queue<int> int_queue;
    
    // queue copy ctor
    std::cout << "\ntesting queue copy ctor:\n";
    Queue<int> int_queue_copy(int_queue);
    std::cout << "size of queue: " << int_queue_copy.size() << "\n";
    std::cout << "\n";

    // queue assignment operator
    std::cout << "\ntesting queue assignment operator:\n";
    Queue<int> int_queue_assign;
    int_queue_assign = int_queue_copy;

    // queue enqueue and dequeue method
    std::cout << "\ntesting queue enqueue method:\n";
    int_queue_copy.enqueue(2);
    std::cout << "size of queue: " << int_queue_copy.size() << "\n";
    std::cout << int_queue_copy.dequeue() << "\n";
    std::cout << "size of queue: " << int_queue_copy.size() << "\n";
    int_queue_copy.enqueue(3);
    std::cout << "size of queue: " << int_queue_copy.size() << "\n";
    int_queue_copy.enqueue(2);
    std::cout << "size of queue: " << int_queue_copy.size() << "\n";
    std::cout << int_queue_copy.dequeue() << "\n";
    std::cout << "size of queue: " << int_queue_copy.size() << "\n";
    int_queue_copy.clear();
    std::cout << "clear size of queue: " << int_queue_copy.size() << "\n";
}