// Composition (and aggregation) v/s Inheritance in C++

// inheritance follows 'is-a' analogy
// Composition follows 'has-a' analogy
// Aggregation follows 'has-a' analogy but lifetime is not necessarily tied to the object

// inheritance creates heirarchy but the other 2 doesn't. They keep it flat

#include <iostream>

struct Point2D
{
    float x, y;
}; // struct is a composite data type as it follows 'has-a' type composition of two floats 'x' and 'y'

class Character
{
public:
    Character(Point2D &ref) : ref_home(ref) {} // We need to provide initialization to ref_home otherwise we can't compile it
    ~Character() {}

private:
    Point2D m_position;
    Point2D m_direction; // This is composition as Character 'has-a' variable(s) of type Point2D

    Point2D &ref_home; // This is aggregation
    // The '&' is just an alias for Point2D object but the scope of Point2D object can be different from this class object
};

Point2D somePointGlobal;

void foo()
{
    Character c(somePointGlobal); // The 'c' is scope is local to this function, but the 'somePointGlobal' exists till end of the program
    // this is aggregation
}

int main()
{
    Point2D somePoint;
    {
        Character someCharacter(somePoint); // The 'someCharacter' scope is between the braces, but 'somePoint' scope is till the end of program
    }
    return 0;
}