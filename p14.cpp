// Inheritance - public, private and protected access levels
/*
Note: Constructors of the base class are not inherited by the derived class automatically.
However, the derived class can call the base class constructor using an initializer list or
through its own constructor.
*/
// Refer the inheritance matrix after referring the example
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

public: // Yes, I can repeat the access specifier
    int m_base_public_member_variable;

protected:
    int m_base_protected_member_variable;

private:
    int m_base_private_member_variable;
};

class Derived : public Base // If we use protected Base, then all the members of Base class are at most protected
{                           // Thus, all the public things are at most of protected level, hence can't be used outside the derived class
public:                     // Same with private,
                            // we can only use public and protected of base in derived but not in outside world
                            // private are never inherited, if we want to inherit that
                            // make derived class a friend of base class or use getter/setter of base
    Derived()
    {
        std::cout << "Derived Constructor" << std::endl;
        m_base_protected_member_variable = 1; // Can be inherired inside derived
        m_base_protected_member_variable = 2; // Can be inherited inside derived
        // m_base_private_member_variable = 3;   // Cannot be inherited, error: 'int Base::m_base_private_member_variable' is private within this context
    }
    ~Derived()
    {
        std::cout << "Derived Destructor" << std::endl;
    }
};

int main()
{
    Derived d;

    // d.m_base_public_member_variable = 1; // no error
    // d.m_base_protected_member_variable = 2; // error: 'int Base::m_base_protected_member_variable' is protected within this context
    // same for private

    return 0;
}

/*
1.Public Inheritance (class Derived : public Base)
    public members → remain public in the derived class.
    protected members → remain protected in the derived class.
    private members → not accessible in the derived class.
    
2. Protected Inheritance (class Derived : protected Base)
    public members → become protected in the derived class.
    protected members → remain protected in the derived class.
    private members → not accessible in the derived class.

3. Private Inheritance (class Derived : private Base)
    public members → become private in the derived class.
    protected members → become private in the derived class.
    private members → not accessible in the derived class.

4. General Rules
    Private members of the base class are never directly accessible in the derived class, regardless of inheritance type.
    Use public inheritance when the derived class "is-a" type of base class.
    Use protected inheritance when you want to restrict access but still allow further derivation.
    Use private inheritance when the derived class "has-a" base class but doesn’t want to expose it.
*/
