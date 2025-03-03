// This will be header file or definition file

#include <string>

class Student // Our new User defined type
{
public:
    // Special actions
    // Actions - Constructor
    Student(); // Default Constructor

    Student(std::string name); // Parametrized Constructor

    void printName();

    // Special actions
    // Actions - Destructor
    // Note: There is no parametrized destructor at all, only parametrized constructors are possible, it makes sense also
    ~Student();

    // Hidden 'fields' or 'attributes' of our class
public:
    std::string m_name;
};