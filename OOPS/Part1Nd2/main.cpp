#include "Student.hpp"
// Compilation: g++ -std=c++17 -o main .\main.cpp .\Student.cpp
int main()
{
    Student mike;
    mike.m_name = "mike s";
    mike.printName();

    Student Sue;
    Sue.m_name = "Sue";
    Sue.printName();

    Student Dhruv("dhruv");
    Dhruv.printName();
    // Destructor will be called for Dhruv first then Sue and mike
    // It follows like popping up from stack

    return 0;
}