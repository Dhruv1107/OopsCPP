// Value Initialization (Zero-Initialization of Members)
// Refer: https://en.cppreference.com/w/cpp/language/value_initialization

#include <iostream>
#include <string>

struct Entity
{
    // Entity() : name(""), collection(nullptr), x(0), y(0) {} // Now zero-initialisation will not work, so need to handle explicitly
    std::string name;
    int *collection;
    int x;
    int y;
};

int main()
{
    Entity e; // It is not initialized, hence all members will be having gargabe values

    int *ptr = new int;

    e.collection = ptr;

    *e.collection = 6;

    std::cout << *e.collection << std::endl;
    std::cout << e.collection << std::endl;
    std::cout << e.name << std::endl;
    std::cout << e.x << std::endl;
    std::cout << e.y << std::endl;

    Entity f{}; // Zero-Initialised, If we have user defined default constructor,
    // then we need to explicitly handle the initialisation of the member variables otherwise they will
    // again get initialised to garbage values

    std::cout << f.collection << std::endl;
    std::cout << f.name << std::endl;
    std::cout << f.x << std::endl;
    std::cout << f.y << std::endl;

    return 0;
}