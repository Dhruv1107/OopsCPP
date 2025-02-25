// Different types of constructor and function signature should match
// Will be splitting the previous code between 3 files

// This will be driver file
#include "Student.hpp"

int main()
{
    Student mike; // Default Constructor is called
    mike.m_name = "mike s";
    mike.printName();

    Student sue;
    sue.m_name = "sue";
    sue.printName();

    Student param("param"); // Parametrized Constructor is called
    // para("papapa"); Error. Since object is a pointer to a class structure and this is not a syntax for calling parametrized constructor
    // Since the object is already created, this syntax is invalid
    // constructors are called at the time of object creation
    // para.m_name = "Example" ;  is a valid statement but this
    param.printName();

    return 0;
}