// Understanding the Vtable (Virtual table)
// this is just intro, detailed will be discussed later
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

    virtual void MemberFunc() // Whenever we have 'virtual', a default member of class, the vtable pointer is initialised by default.
                                // vtable pointer points to the virtual table
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

    void MemberFunc() override // To overrirde a Base class member we need to make it virtual
    {
        std::cout << "Derived::MemberFunc()" << std::endl;
    }
};

int main()
{
    // Create a Base* that can point to 'Base' or 'Derived', i.e. anything that 'is-a' Base or Derived
    // We also have a vtbl that is created for this instance of the object
    Base *instance = new Derived; // Since Base is inherited by derived, it is non issue to instantiate 'instance' as Derived

    // When we call a member function, the vtbl points us to the correct member function
    instance->MemberFunc(); // We thought it would call derived MemberFunc but instead it called Base MemberFunc().
    // In case if we want to call Derived MemberFunc(), we can use use virtual function concept. Now making virtual in Base and adding override in derived

    delete instance; // need to delete it manually since its on heap

    instance = new Base;
    instance->MemberFunc();
    delete instance;

    return 0;
}