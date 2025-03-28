#include "IntArray.hpp"
#include <iostream>

// Constructor
IntArray::IntArray(std::string name) : m_name(name), m_data(new int[10])
{
    std::cout << m_name << " was constructed" << std::endl;
}
// Destructor
IntArray::~IntArray()
{
    std::cout << m_name << " was destructed" << std::endl;
    delete[] m_data;
}
// Copy Constructor policy
IntArray::IntArray(const IntArray &rhs)
{
    m_name = rhs.m_name + "(copy)";
    std::cout << " was copy constructed from: " << rhs.m_name << std::endl;
    m_data = new int[10];
    for (int i = 0; i < 10; i++)
    {
        m_data[i] = rhs.m_data[i];
    }
}
// Copy assignment operator policy
IntArray &IntArray::operator=(const IntArray &rhs)
{
    if (this != &rhs) // making sure we are not assigning an object to itself
    {
        delete[] m_data;
        m_name = rhs.m_name;
        std::cout << " was copy assigned from " << rhs.m_name << std::endl;
        m_data = new int[10];
        for (int i = 0; i < 10; i++)
        {
            m_data[i] = rhs.m_data[i];
        }
    }

    return *this;
}
// Move constructor
IntArray::IntArray(IntArray&& source) //rvalue reference
{
    m_name = source.m_name;  // Steal the name
    source.m_name = "";       // Empty out the old object

    m_data = source.m_data;   // Steal the data pointer
    source.m_data = nullptr;  // Nullify the old pointer

    std::cout << m_name << " was move constructed" << std::endl;
}
// Move assignment operator
IntArray &IntArray::operator=(IntArray &&source)
{
    if (this != &source)
    {
        m_name = source.m_name;
        source.m_name = "";
        m_data = source.m_data;
        source.m_data = nullptr;
        std::cout << m_name << " used move assignment" << std::endl;
    }

    return *this;
}
