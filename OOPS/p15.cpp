// inheritance calling different constructors
/*
In C++, when you define a derived class, you are creating a new class that extends the functionality
of a base class. The constructor of the derived class is responsible for initializing both its own
data members and the members of the base class.

However, in C++, the base class constructor is not called automatically
(except in certain special cases like default construction or when no explicit call is made).
Instead, you must explicitly call the constructor of the base class in the initializer list of
the derived class constructor.

This explicit call is needed because the derived class does not have access to the private members
of the base class directly, and because the base class may have different constructors,
some of which may require arguments. This way, you control how the base class is initialized
before the body of the derived class constructor executes.

Why Not Automatic?:

Base class construction is separate from the derived class construction.
The base class may have different constructors with varying parameter lists, and C++ needs to know exactly which one to call.
If no explicit call is provided, C++ will call the default constructor of the base class automatically (if one exists).
In your case, TopLevelClass requires a std::string argument. If the derived class doesn't explicitly call this constructor,
the compiler would not know how to initialize the base class properly, and it would result in a compilation error.

No Automatic Calls with Parameters: C++ doesn't automatically infer which constructor of the base class
to call when it requires arguments. The compiler cannot make assumptions about the arguments or the
intention of the programmer. Therefore, you must explicitly call the appropriate constructor of the
base class from the derived class.

Multiple Constructors in Base Class: If the base class has more than one constructor
(e.g., a default constructor and a parameterized constructor), the derived class must explicitly
choose which one to call. C++ cannot automatically choose for you.

*/

#include <string>
#include <iostream>

class TopLevelClass
{
public:
    TopLevelClass(std::string name)
    {
        std::cout << "TopLevelClass Constructor" << std::endl;
    }
    ~TopLevelClass()
    {
        std::cout << "TopLevleClass Destructor" << std::endl;
    }
};

class EntityBase : public TopLevelClass
{
public:
    EntityBase() : TopLevelClass("name") // Need to call since no default ctor
    {
        std::cout << "EntityBase Constructor" << std::endl;
    }
    EntityBase(std::string name) : TopLevelClass("name"), m_name(name) // Need to call
    {
        std::cout << "EntityBase(name) Constructor" << std::endl;
    }
    ~EntityBase()
    {
        std::cout << "EntityBase Destructor" << std::endl;
    }

private:
    std::string m_name;
};

class Monster : public EntityBase
{
public:
    Monster() : EntityBase("name") // need to call here to call parametrized ctor as by default 'default ctor will be inherited'
    {
        std::cout << "Monster Constructor" << std::endl;
    }
    Monster(std::string name) //: EntityBase("name") //If we don't provide this then no worries, as default ctor of EntityBase will be inherited
    {
        std::cout << "Monster(name) Constructor" << std::endl;
    }
    ~Monster()
    {
        std::cout << "Monster Destructor" << std::endl;
    }
};

int main()
{
    Monster badMonster("MandM");

    return 0;
}

// Observations:
//  So, by default 'default ctor' is inherited to each ctor of derived class
//  If no default ctor, like TopLevelClass, then we need to call it for every ctor in derived class
// As ctor are not inherited and we need to construct base class before derived class

// Also we cannot skip level in Inheritance heirarchy like calling TopClassLevel() in monster as they are not directly inherited

// Output:
/*
TopLevelClass Constructor
EntityBase Constructor
Monster(name) Constructor
Monster Destructor
EntityBase Destructor
TopLevleClass Destructor
*/