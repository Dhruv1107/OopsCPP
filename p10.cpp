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
    return result;
}

int main()
{
    // IntArray array1("array1");
    // IntArray array2 = array1; // copy constructor
    // IntArray array3("array3");
    // array3 = array1; // copy assignment
    // foo(array2);
    // foo();
    // IntArray array4 = foo(); // foo() will call para ctor, so no cpy ctor is called, its just we are storing return value of foo

    // Move ctor example
    std::vector<IntArray> myArrays;
    myArrays.reserve(10); // reserving vector size
    for (int i = 0; i < 10; i++)
    {
        IntArray temp(std::to_string(i)); // ctor call
        // myArrays.push_back(temp);            // copy ctor call
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