#ifndef STUDENT_HPP
#define STUDENT_HPP
// The #ifndef and #define macros in the Student.hpp file are used to prevent multiple inclusions of the same header file,
// which can cause errors and increase compilation time. This technique is known as an "include guard."
using namespace std;

#include <string>

class Student
{
public:
    // By default everything is private in a class
    Student(); // Constructor => allocates the memory and returns the object
    Student(string name);
    ~Student();
    void printName();
    string m_name;
};

#endif