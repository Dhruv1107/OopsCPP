// Explicit ctor and list initialization to avoid implicit(automatic) conversions done by compiler
// NOTE: Always use explicit constructor and try initilization using curly brackets {}
#include <iostream>
#include <string>

class udt
{
public:
    explicit udt(int);

private:
    int m_variable;
};

udt::udt(int i)
{
    m_variable = i;
    std::cout << "m_variable: " << m_variable << std::endl;
}

int main()
{
    // udt u1 = 500.0012f; // after adding explicit we'll see error: conversion from 'float' to non-scalar type 'udt' requested
    // udt u1 = 500; // after adding explicit we'll see error: conversion from 'int' to non-scalar type 'udt' requested
    // This type of initialization(using =) is not done when we add explicit

    udt u1(500.012f); // This will work fine
    // udt u2{500.012f}; // This will not work, error: narrowing conversion of '5.00011993e+2f' from 'float' to 'int' [-Wnarrowing]
    // Narrowing by compiler is not allowed with/without explicit when we use '{}' for initialization hence error
    // udt u1{500}; // This works when using with/without explicit
    return 0;
}