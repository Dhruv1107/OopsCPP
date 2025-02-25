// Member Initializer List
// Refer more: https://isocpp.org/wiki/faq/ctors#init-lists
#include <iostream>

class Vector3f
{
public:
    // Member Initialization list
    Vector3f() : x(0.0f), y(0.0f), z(0.0f)
    {
        /*x = 0.0f;
        y = 0.0f;
        z = 0.0f;*/
    }

    float x, y, z; // order here will matter while initializing in list, so use same order for initialization else garbage value will be there for the affected member
};

std::ostream &operator<<(std::ostream &os, const Vector3f &obj)
{
    os << obj.x << "," << obj.y << "," << obj.z;

    return os;
}

int main()
{
    Vector3f myVector;
    std::cout << myVector << std::endl;

    return 0;
}