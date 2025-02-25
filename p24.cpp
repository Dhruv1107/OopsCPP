// Multiple Inheritance Revisited (Virtual Inheritance)

#include <iostream>

struct Entity
{
    int x{4}, y{5};
};

struct Warrior : virtual public Entity
{
    int power{10};
};

struct Goblin : virtual Entity
{
    int power{7};
};

struct Player : Warrior, Goblin // here virtual will not work
{
};

int main()
{
    Player mike;

    // std::cout << mike.x << std::endl; // error: request for member 'x' is ambiguous
    // Its ambiguous because Player inherits from both: Warrior and Goblin
    // and while calling 'x' compiler cannot decide which 'x' to call: either of Warrior or Goblin
    // It happens because both: warrior and goblin has their own separate copy of Entity where 'x' is defined
    // To remove this ambiguity, we should share the same copy between the Goblin and Warrior
    // and thus both Goblin and Warrior will be having the same 'x' -- Thus no ambiguity
    // This is what exacltly is achieved by using 'virtual' when inheriting a class

    std::cout << mike.Warrior::x << std::endl; // Instead specify which 'x' to remove ambiguity
    std::cout << mike.Goblin::x << std::endl;

    // We can add virtual keyword while inheriting to solve this, but remember this will only work between the derived classes and base class where
    // base class is common for all derived classes
    // In other words, this will work only when 1 base class is there for all the derived classes
    // in this example, Entity is the 'common' base class for its derived: 'Warrior' and 'Goblin'
    // this will work for them but not for Player since it inherits from 2 diff classes: Warrior and Goblin
    // The player will still have have ambiguity when we call 'power' as it is defined in both the base classes for Player
    // and thus induces ambiguity for Player while compiling

    // The virtual will make only single copy of base class for all the derived classes

    std::cout << mike.x << std::endl; // now this will work

    // std::cout << mike.power << std::endl; // error: request for member 'power' is ambiguous

    std::cout << mike.Goblin::power << std::endl; // this will work

    return 0;
}