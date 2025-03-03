#include <iostream>
#include <string>

using namespace std;

class Student // Our new User defined type
{
public:
    // Special actions
    // Actions - Constructor
    Student()
    {
        cout << "Constructor" << endl;
    }

    // Special actions
    // Actions - Destructor
    // Note: There is no parametrized destructor at all, only parametrized constructors are possible, it makes sense also
    // as destructors are only required to free the resources held by the object
    ~Student()
    {
        cout << "Destructor" << endl;
    }

    // Remember C++ provides default constructor and destructor also
    // Also it provides default copy constructor

    // Hidden 'fields' or 'attributes' of our class
private:
    string m_name;
};

int main()
{

    // An instance of a 'Student' (i.e. an object)
    Student mike; // Constructor called here to create the object and as soon as mike goes out of scope the destructor will be called to destroy the object

    // mike.m_name = "mike s"; // This will give compilation error as 'm_name' is private member
    // Destruction order of objects is reverse of construction due to Stack
    return 0;
}

// Should divide above code into 3 files: Student.hpp, Student.cpp and driver file which is implementing main()
// Student.hpp: Only Class definition with member decalartions
// Stduent.cpp: All Class class member definitions
// Driver File (having main()): Calls to class members