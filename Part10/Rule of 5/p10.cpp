// p10: didvided into 3: header, implementation and driver file
// Move constructor and Move assignment operator
// They together constitute Rule of 5
#include "IntArray.hpp"
#include <vector>
#include <iostream>
void foo(IntArray temp) {} // copy ctor will be called since its pass by value

IntArray foo()
{
    IntArray result("foo created array"); // Parametrized ctor will be called
    return result;  // When returning and storing the return value no copy constructor is called by some compiler magic.
}

int main()
{
    // IntArray array1("array1");
    // IntArray array2 = array1; // copy constructor
    // IntArray array3("array3");
    // array3 = array1; // copy assignment
    // foo(array2); // When pass by value is used then copy constructor is called
    // foo();
    // IntArray array4 = foo(); // foo() will call parameterized constructor, so no copy constructor is called,
                                // its just we are storing return value of foo
                                // Copy Constructor is not called because of return value optimization.
    // Move constructor example
    // Used when we don't want to use copy constructor and only want to steal/transfer the resources
    std::vector<IntArray> myArrays;
    myArrays.reserve(10); // reserving vector size
    /* 
        If myArrays had not been reserved using myArrays.reserve(10), then when myArrays grows beyond its current capacity, a reallocation would happen.
        Reallocation involves copying all existing elements into a new larger memory block, leading to additional calls to the copy constructor.
    */
    for (int i = 0; i < 10; i++)
    {
        IntArray temp(std::to_string(i)); // constructor call
        // myArrays.push_back(temp);            // copy constructor call
        /*
            The function push_back(temp) takes temp as an lvalue, meaning it uses the copy constructor to insert it into the vector.
            The temp object, created inside the loop, is copied into myArrays, and then temp is destructed.
            Each iteration results in a new object being constructed, copied, and then destructed.
        */
       // 23 allocations were used, can check using valgrind
        /*  0 was constructed
             was copy constructed from: 0
            0 was destructed
            1 was constructed
             was copy constructed from: 1
            1 was destructed
            2 was constructed
             was copy constructed from: 2
            2 was destructed
            3 was constructed
             was copy constructed from: 3
            3 was destructed
            4 was constructed
             was copy constructed from: 4
            4 was destructed
            5 was constructed
             was copy constructed from: 5
            5 was destructed
            6 was constructed
             was copy constructed from: 6
            6 was destructed
            7 was constructed
             was copy constructed from: 7
            7 was destructed
            8 was constructed
             was copy constructed from: 8
            8 was destructed
            9 was constructed
             was copy constructed from: 9
            9 was destructed
            0(copy) was destructed
            1(copy) was destructed
            2(copy) was destructed
            3(copy) was destructed
            4(copy) was destructed
            5(copy) was destructed
            6(copy) was destructed
            7(copy) was destructed
            8(copy) was destructed
            9(copy) was destructed*/
        myArrays.push_back(std::move(temp)); // no copy ctor call and is more efficient since copy ctor is heavier than move ctor
        /*
            std::move(temp) does not actually move anything by itself. Instead, it casts temp to an rvalue reference (IntArray&&), meaning it tells the compiler:
            "Hey, I don’t need temp anymore, so feel free to move its resources instead of copying them."
            This allows push_back to invoke the move constructor instead of the copy constructor.
        */
       // 13 allocations were used, can check using valgrind
        /*  0 was constructed
            0 was move constructed
             was destructed
            1 was constructed
            1 was move constructed
             was destructed
            2 was constructed
            2 was move constructed
             was destructed
            3 was constructed
            3 was move constructed
             was destructed
            4 was constructed
            4 was move constructed
             was destructed
            5 was constructed
            5 was move constructed
             was destructed
            6 was constructed
            6 was move constructed
             was destructed
            7 was constructed
            7 was move constructed
             was destructed
            8 was constructed
            8 was move constructed
             was destructed
            9 was constructed
            9 was move constructed
             was destructed
            0 was destructed
            1 was destructed
            2 was destructed
            3 was destructed
            4 was destructed
            5 was destructed
            6 was destructed
            7 was destructed
            8 was destructed
            9 was destructed*/
    }
    return 0;
}