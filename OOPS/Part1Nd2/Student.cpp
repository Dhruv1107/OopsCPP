#include "Student.hpp"

#include <iostream>
using namespace std;

Student::Student()
{
    // Good way to initialize member variables in a constructor
    cout << "Constructor" << endl;
}

/*
: m_name(name) (Initialization List)
This initializes the member variable m_name with the argument name before the constructor body executes.
This is more efficient than assigning m_name = name; inside the constructor body.
*/
Student::Student(string name) : m_name(name)
{
    cout << "Parameterized Constructor" << endl;
    // m_name = name;
}

Student::~Student()
{
    cout << "Destructor:" << m_name << endl;
}

void Student::printName()
{
    cout << "name is " << m_name << endl;
}