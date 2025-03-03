// Static variables are allocated in the binary(object file or executable object file). They are not in either heap or stack.

#include <iostream>

struct API
{
    API() {}
    ~API() {}

    static int GetMajorAttributes()
    {
        // std::cout << this << std::endl; //error: 'this' is unavailable for static member functions
        return MAJOR; // static functions can only return static values
    }

    static int MAJOR;
    const static int MINOR = 6; // static with const can be initialised
    // else we'll see this error: error: ISO C++ forbids in-class initialization of non-const static member 'API::MINOR'
};

// static variables in a class exists outside of the class. The scope is within the class however.
// The class can only hold declaration of the static variables thus they are need to be defined outside of the class.
// These variables live outside of the class and have their own storage.
// Ther are not tied to the object of the class. They will be shared among all the objects of t he class

int API::MAJOR = 7; // Now missing definition is added and thus the linker error will not come now

int main()
{
    API instance;
    std::cout << "Major: " << API::MAJOR << std::endl;
    instance.MAJOR = 8; // linker error: undefined reference to `API::MAJOR' [observe '::' scope resolution operator, its like declaration and not definition]
    std::cout << "Major: " << API::MAJOR << std::endl;

    std::cout << "major: " << API::GetMajorAttributes() << std::endl;
    return 0;
}

/*
Where Static Variables Reside in RAM
Static variables (whether global, local, or class member static variables) do not reside in the stack. They also do not reside in the heap unless dynamically allocated.

They are stored in the Data Segment of the RAM.

a. Initialized Static Variables:
These are stored in the Initialized Data Segment. If you declare a static variable and initialize it,
like static int x = 5;, it will reside in the Initialized Data Segment.

Example:

static int count = 0; // Initialized static variable
When the program starts, the Operating System (OS) loads the variable count into the Initialized Data Segment of RAM.
It will hold the value 0 until it is changed during the program's execution. The value is retained throughout the
program’s lifetime.

b. Uninitialized Static Variables:
These are stored in the BSS Segment of the Data Segment. Static variables that do not have an explicit initializer
are placed here, and they are initialized to zero (or NULL for pointers) by the system at the time the program starts.

Example:

static int count; // Uninitialized static variable
Since count is uninitialized, the system will place it in the BSS Segment, and it will be set to zero at program startup.

*/