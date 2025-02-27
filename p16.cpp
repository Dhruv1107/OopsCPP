// Virtual Functions(Dynamic Dispatch)
#include <iostream>

class Base
{
public:
    Base()
    {
        std::cout << "Base Constructor" << std::endl;
    }
    ~Base()
    {
        std::cout << "Base Destructor" << std::endl;
    }

    virtual void MemberFunc() // To overrirde a Base class member we need to make it virtual
    {
        std::cout << "Base::MemberFunc()" << std::endl;
    }
};

class Derived : public Base
{
public:
    Derived()
    {
        std::cout << "Derived Constructor" << std::endl;
    }

    ~Derived()
    {
        std::cout << "Derived Destructor" << std::endl;
    }

    void MemberFunc() override // I need the Derived class to override any member functions in the base class
    {
        std::cout << "Derived::MemberFunc()" << std::endl;
    }
};

int main()
{
    /*
        Base baseInstance;
        baseInstance.MemberFunc(); // Will call the Base::MemberFunc()

        Derived instance;
        instance.MemberFunc(); // Will call the Derived::MemberFunc()
    */
    Base *instance = new Derived; // Since Base is inherited by derived, it is non issue to instantiate 'instance' as Derived. Thus 'instance' is derived type.
    // Derived is a type of Base type => at run time we are changing the type
    // We are allocating the memory for Derived type
    instance->MemberFunc(); // We thought it would call derived MemberFunc but instead it called Base MemberFunc().

    // In case if we want to call Derived MemberFunc(), we can use use virtual function concept. Now making virtual in Base and adding override in derived

    delete instance; // need to delete it manually since its on heap
    /*
    Output after all modifications:
    Base Constructor
    Derived Constructor
    Derived::MemberFunc()
    Base Destructor
    Notice Derived Destructor is not called. This is discussed in next lesson 'Vtable' or 'p16'
    */

    /*
        To call the base member function using the virtual function use scope resoulution operator
        Base *instance = new Derived;
        instance->Base::MemberFunc(); //This will call the Base::MemberFunc() instead of Derived.
    */
    return 0;
}