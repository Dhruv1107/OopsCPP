// In-Class Initializer

#include <iostream>
#include <string>

struct Entity
{
    Entity() : name{"First"}, collection{nullptr}, x{1}, y{1} {}
    std::string name{""};
    int *collection{nullptr};
    int x{2}; // In-class member initialiser
    int y{2};
};

int main()
{
    Entity e{}; // Zero_initialiser
    // Now what will be precedence for Initialisation:
    // Precedence: First Default Constructor then in-class member initialiser then the zero-initialiser

    std::cout << e.collection << std::endl;
    std::cout << e.name << std::endl;
    std::cout << e.x << std::endl;
    std::cout << e.y << std::endl;

    return 0;
}