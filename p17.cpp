// Virtual Destructors (Make base class destructor virtual)
/*
Problem Without Virtual Destructor
If you call delete on a base class pointer that points to a derived class object,
and the destructor of the base class is not virtual, only the base class destructor
will be invoked. This means the derived class's destructor will not be called, leading
to incomplete destruction of the object.
*/
#include <iostream>

class Base
{
public:
    Base()
    {
        std::cout << "Base Constructor" << std::endl;
        baseData = new int[10];
    }
    virtual ~Base() // making virtual will force inheritance heirarchy to call destructor.
                    // Remove the virtual and see the memory leak of 60 bytes in valgrind.
    {
        std::cout << "Base Destructor" << std::endl;
        delete[] baseData;
    }

    virtual void MemberFunc()
    {
        std::cout << "Base::MemberFunc()" << std::endl;
    }
    int *baseData;
};

class Derived : public Base
{
public:
    Derived()
    {
        std::cout << "Derived Constructor" << std::endl;
        derivedData = new int[15];
    }

    ~Derived()
    {
        std::cout << "Derived Destructor" << std::endl;
        delete[] derivedData;
    }

    void MemberFunc() override // To overrirde a Base class member we need to make it virtual
    {
        std::cout << "Derived::MemberFunc()" << std::endl;
    }
    int *derivedData;
};

int main()
{
    Base *instance = new Derived; // Since Base is inherited by derived, it is non issue to instantiate 'instance' as Derived

    instance->MemberFunc(); // We thought it would call derived MemberFunc but instead it called Base MemberFunc().

    // In case if we want to call Derived MemberFunc(), we can use use virtual function concept. Now making virtual in Base and adding override in derived

    delete instance; // need to delete it manually since its on heap

    return 0;
}
/*
How Does a Virtual Destructor Work?
When you mark a destructor as virtual, C++ sets up a vtable (virtual table) for the class.
The vtable stores pointers to the virtual functions of the class. The vtable mechanism ensures
that the correct destructor (for the actual object type, not the pointer type) gets called at runtime.

Here’s how the mechanism works in practice:

Base Class Destructor: When an object is deleted via a base class pointer, the vtable of the object will
be used to call the derived class's destructor (if the destructor is virtual).

Derived Class Destructor: The derived class's destructor is called first, then the base class's destructor
is called automatically as part of the destruction process. This is the reverse order of construction.
*/

/*
How vtables Work in the Context of Inheritance:
Even if a derived class does not declare any virtual functions, it still has a vtable.
This vtable is created because the base class has virtual functions (such as a virtual destructor or any other virtual function).
The vtable of the derived class will:
    1.Inherit the vtable of the base class: The derived class will inherit the base class's vtable (if the base class has virtual functions),
    but it can still override any virtual functions if it defines them.
    2.Point to the base class's virtual functions: If the derived class does not declare any additional virtual functions, its vtable will essentially
    point to the base class’s virtual functions (or its own override of those functions if any).
*/