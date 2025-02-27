// Intro to Inheritance

#include <iostream>

class Dog // Base Class
{
public:
    void Bark()
    {
        std::cout << "bark!" << std::endl;
    }

    void Walk()
    {
        x += 1;
        y += 1;
    }

    float x, y;
};

class Golden : public Dog // Inheriring Dog class(called derived class or subclass)
{
public:
    Golden() : m_sticksRetrieved{0} {}
    void Retrieve() // additional Golden Retriever attributes
    {
        std::cout << "Retrieving a stick" << std::endl;
        m_sticksRetrieved++;
        std::cout << "Sticks Retrieved: " << m_sticksRetrieved << std::endl;
    }

    float m_sticksRetrieved;
};

class Husky : public Dog
{
};

int main()
{
    Golden dog1;
    dog1.Bark();
    dog1.Walk();
    dog1.Retrieve();
    dog1.Retrieve();

    Husky dog2;
    dog2.Bark();
    dog2.Walk();

    return 0;
}