// Operator Overloading
// Bonus: See overloading of comparison opeartor '<' and function call operator'()'
#include <iostream>

// A vector3 is a user defined data type, storing floats

class Vector3f
{
public:
    Vector3f()
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
    }
    // Adding const since its logical as 'x','y' and 'z' should not be modified while performing addition
    Vector3f operator+(const Vector3f &rhs) const // adding const makes all the member variables read -only
    {
        Vector3f result; // Default ctor will be called
        // x += 1; due to const, this will be unmodifiable
        // hence we're doing workaround with const by creating new object and return that object
        result.x = x + rhs.x;
        result.y = y + rhs.y;
        result.z = z + rhs.z;

        return result; // Here destructor for result willbe called to destroy as it will be going out of scope
    }

    Vector3f operator++() // this is prefix increment operator or pre-increment
    {
        x = x + 1;
        y = y + 1;
        z = z + 1;
        return *this;
    }

    bool operator==(const Vector3f& rhs) {
        std::cout<<"part of class"<<std::endl;
        if(x == rhs.x && y==rhs.y && z == rhs.z) {
            return true;
        }
        return false;
    }

    float x, y, z;
};

bool operator==(const Vector3f& lhs, const Vector3f& rhs) {
    std::cout<<"outside of class"<<std::endl;
    if(lhs.x == rhs.x && lhs.y==rhs.y && lhs.z == rhs.z) {
        return true;
    }
    return false;
}

// To overload ostream operator '<<' we need to do as follows (refer cppreference)
// Note: It can't be declared inside a class, see return type (ostream)
std::ostream &operator<<(std::ostream &os, const Vector3f &obj)
{
    os << obj.x << "," << obj.y << "," << obj.z;

    return os;
}

int main()
{
    Vector3f myVector;
    myVector.x = 1.f;
    myVector.y = 2.f;
    myVector.z = 3.f;

    Vector3f myVector2;
    myVector2.x = 3.f;
    myVector2.y = 2.f;
    myVector2.z = 1.f;

    Vector3f result;
    result = myVector + myVector2; // '+' operator overloading

    std::cout << result.x << " " << result.y << " " << result.z << std::endl;

    ++result; // prefix operator overloading
    ++result;
    // std::cout << result.x << " " << result.y << " " << result.z << std::endl;

    std::cout << result << std::endl; // operator '<<' overloading

    myVector2.x = 1.f;
    myVector2.y = 2.f;
    myVector2.z = 3.f;

    if(myVector == myVector2) {
        std::cout<<"vectors are equal"<<std::endl;
    } else {
        std::cout<<"vectors are not equal"<<std::endl;
    }

    return 0;
}