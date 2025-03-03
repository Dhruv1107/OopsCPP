// pIMPL (pointer to implementation) - More stable APIs

// This is driver file
// Other 2 files are person.hpp and person.cpp

#include <iostream>
#include "person.hpp"

int main()
{
    Person mike("mike");

    std::cout << mike.GetAttributes() << std::endl;

    return 0;
}