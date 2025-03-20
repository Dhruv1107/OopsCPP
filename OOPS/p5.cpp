#include <iostream>
#include <string>

class myArray
{

public:
    static int k; // Need to make inline to resolve linking errors, or define it outside the class
    // inline enables external linkage, same variable can be used in multiple cpp files and
    // compiler makes sure they all share the single definition of that variable
    // inline static int k = 0;: This declares k as an inline static variable and initializes it to 0. The inline keyword allows this variable to be defined in a header file and included in multiple translation units without causing linker errors.
    // Using inline with static variables ensures that there is only one definition of the variable across all translation units, preventing linker errors and maintaining the correct behavior of the program.
    /*
    Important Considerations
        Cannot Be Used for All Variables: Inline variables are best suited for variables that need to be defined in a header and shared across multiple files. It's most commonly used for constants or global variables.

        Initialization Required: You must provide an initializer for inline variables because they need to have a concrete value when the header is included.

        Multiple Definitions: If you define an inline variable without initializing it, or with conflicting initializers across translation units, you'll get a linker error.

        Thread-Safety: Like all global variables, the use of inline variables requires careful consideration for thread-safety if they are accessed concurrently by multiple threads. You may need to protect them using mutexes or atomic operations.
    */

    int l;

    myArray()
    {

        std::cout << "Default Constructor" << std::endl;
        data = new int[10];

        for (int i = 0; i < 10; i++)
        {
            data[i] = i * i;
        }
    }

    ~myArray()
    {
        std::cout << "deleting: " << data << std::endl;
        delete[] data;
    }

    // Own Copy Constructor
    myArray(const myArray &rhs)
    {
        std::cout << "Copy Constructor" << std::endl;
        data = new int[10];

        for (int i = 0; i < 10; i++)
        {
            data[i] = rhs.data[i];
        }
    }

    // Copy Assignment Operator
    // Called when object is already created, we are just making a copy later (e.g. a2 = a1)
    myArray &operator=(const myArray &rhs)
    {

        std::cout << "Copy Assignment Operator" << std::endl;

        if (&rhs == this) // when suppose a2 = a2, doesn't make sense, so do nothin and return current object
        {
            return *this;
        }

        // perfrom copy of the values in other object i.e. on rhs
        delete[] data; // deleting other objects data and allocating new data for this object
        data = new int[10];

        for (int i = 0; i < 10; i++)
        {
            data[i] = rhs.data[i];
        }

        return *this; // Need to return the new object i.e. on lhs;
    }

    void printArray()
    {
        for (int i = 0; i < 10; i++)
        {
            // std::cout << data[i] << std::endl;
        }
    }

    void setData(int index, int value)
    {
        data[index] = value;
    }

private:
    int *data;
};

int myArray::k; // definition of static class variable else linker will throw undefined reference
// As static members are not associated with the object. They are initialised only and exists through the lifetime of
// the program
// Static is a separate storage class

void Print(myArray a)
{
    a.printArray();
}

void printReference(myArray &c)
{
    c.printArray();
}

int main()
{
    myArray a;         // different object addrress
    myArray b = a;     // Copy Constructor called
    Print(b);          // Copy Constructor called
    Print(b);          // Copy Constructor called
    printReference(b); // Copy Constructor not-called since we are passing only reference of the object and not the object
    // If passed by value then we need to make a copy, hence default copy constructor will be called but in reference this will not be the case

    // Another way to handle is to move the copy constructor in the private section
    // Or use this syntax: myArray(const myArray &rhs)=delete; in the public section => We tell compiler don't make a copy constructor, if made delete it.

    // myArray::k = 2;
    std::cout << myArray::k << std::endl; // 0
    a.k = 3;                              // you can access a static variable using either the class name or an object of the class
    b.k = 5;                              // it is generally recommended to use the class name to access static variables to make it clear that the variable is shared among all instances of the class

    a.l = 1;
    b.l = 2;

    std::cout << a.k << std::endl; // 5
    std::cout << b.k << std::endl; // 5

    std::cout << a.l << std::endl; // 1
    std::cout << b.l << std::endl; // 2
}