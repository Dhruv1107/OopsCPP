#ifndef STUDENT_HPP
#define STUDENT_HPP

using namespace std;

#include <string>

class Student {
    public:
    //By default everything is private in a class
        Student();  //Constructor => allocates the memory and returns the object
        Student(string name);
        ~Student();
        void printName();
        string m_name;
};

#endif