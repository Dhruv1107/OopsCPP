// This will be implementation file or library file
#include <iostream>
#include "p2Student.hpp" //To get our Class in the scope of this file

// Need to use Class Scope '::' operator, to access class members

Student::Student()
{
    std::cout << "User-defined Default Constructor" << std::endl;
}

Student::Student(std::string name)
{
    m_name = name; // We can directly access class members(even private) within member functions
    std::cout << "Parametrized Constructor" << std::endl;
}

Student::~Student()
{
    std::cout << "User-defined Default Destructor for: " << m_name << std::endl;
}

void Student::printName()
{
    std::cout << "Name is " << m_name << std::endl;
}