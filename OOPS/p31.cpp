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

    std::cout << mike.GetAge() << std::endl;    //500

    std::cout << mike.GetThisAddress() << std::endl;    //0x7fc51ffb44
    std::cout << &mike << std::endl;    //0x7fc51ffb44
    // For both these we get the same address

    Person* Rishit = new Person(700);
    std::cout<<Rishit->GetThisAddress()<<std::endl; //0x242880abaf0
    std::cout <<Rishit << std::endl;    //0x242880abaf0

    delete Rishit;
    
    return 0;
}