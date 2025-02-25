// Delegating Constructors - Avoid Repeating Yourself

#include <iostream>
#include <string>

struct Entity
{
    Entity() : name{}, collection{nullptr}, x{0}, y{0}
    {
        std::cout << "Default Constructor" << std::endl;
        init();
    }

    Entity(std::string _name) : Entity() // Delegating Constructors
    // Instead of repeating what Default Constructor did, we can just make a call to it
    // Thus that work will not be repeated explicitly
    // Thus we need not call init() here explicilty
    // The goal is to Not Repeat Ourselves or Don't Repeat Yourself(DRY)
    // Note: The delegating ctor call cannot be mixed with initializing members at same time
    // Ex: Entity(std::string _name) : Entity(), name{"test"} {some code}
    {
        std::cout << "Para Constructor" << std::endl;
        name = _name;
    }
    ~Entity()
    {
        std::cout << "Destructor: " << name << std::endl;
    }
    std::string name;
    int *collection;
    int x;
    int y;

private:
    void init() // Suppose we're required to call it in every time an object is created
    {
        x = 7;
        y = 5;
        name = std::to_string(x) + std::to_string(y);
    }
};

int main()
{
    Entity e("mike");
    Entity f;

    /*
    Output:
        Default Constructor //Called Def Constructor by 'e'
        Para Constructor //OG Para Constructor
        Default Constructor //'f' object created
        Destructor //'f' destroyed
        Destructor // 'e' destroyed
    */
}
