// The 'this' keyword

//'This' is a pointer to the current instance of object

#include <iostream>

class Person
{
public:
    Person(int age)
    {
        // age = age;// this will not work, It is ambiguous and compiler gets confused b/ actual parameter and member variable
        // member initilization list doesn't have this problem though, it is able to differentiate
        this->age = age;
    }

    int GetAge() const
    {
        return age;
    }

    Person *GetThisAddress()
    {
        // std::cout << this << std::endl;
        return this;
    }

private:
    int age;
};

int main()
{
    Person mike(500);

    std::cout << mike.GetAge() << std::endl;

    std::cout << mike.GetThisAddress() << std::endl;
    std::cout << &mike << std::endl;

    return 0;
}