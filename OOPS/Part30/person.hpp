#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>
#include <memory>

class Person
{
    public:
    Person(std::string s);
    ~Person();
    
    std::string GetAttributes();
    
    private:
    struct pImplPerson; // Forward declaration of struct
    // pImplPerson* m_impl; // This approach will actually hide the information from client
    // that we don't want to share
    // Better we make it a unique ptr
    std::unique_ptr<pImplPerson> m_impl;
    //  std::string m_name;
    //  std::string m_strength;
    //  std::string m_speed;
};

#endif