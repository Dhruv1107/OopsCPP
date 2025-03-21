// friend function
// Refer: https://en.cppreference.com/w/cpp/language/friend
// The friend declaration appears in a class body and grants a function or another class access to private and protected members of the class where the friend declaration appears.
// Most commonly used in operator overloading
#include <iostream>

class PrivateSecurityInfo
{
    int passcode;
    friend class UserDefinedTypes;  // It tells class UserDefinedTypes is my friend and he can look up my private info
};

class UserDefinedTypes
{
public:
    friend void PrintPrivateMemberVariable(UserDefinedTypes u); // after adding this the error will be gone, it can be added in private also
    // We are giving PrintPrivateMemberVariable function the permission to access the private variables
    // it doesnt matter as long as it is declared in the class
    // So basically this function is my friend and he can access my private info
    PrivateSecurityInfo m_info; // since we declared this class as friend in PrivateSecurityInfo, we can access its private members
    UserDefinedTypes() : m_privateMemberVariable(0) { m_info.passcode = 9; }

private:
    int m_privateMemberVariable;
};

void PrintPrivateMemberVariable(UserDefinedTypes u)
{
    std::cout << "m_privateMemberVariable " << u.m_privateMemberVariable << std::endl;
    // Why Not able to access passcode from 'u' here [u.m_info.passcode is invalid]?
    /*
    In C++, friend classes are given special access to a class's private and protected members.
    This means that a friend class can access the private and protected members of the class that declares
    it as a friend, even though these members would otherwise be inaccessible to regular classes outside the class.

    However, even though a friend class has special access to another class's private/protected members,
    it does not inherit those access rights. This means that the friend class cannot automatically access
    the private/protected members of its own derived classes or its base classes just because it is a friend
    to another class.

    A friend class is not part of the class hierarchy of the class it’s a friend to,
    and it doesn't gain any "inheritance rights" to access members of other classes unless explicitly granted.
    */
}

int main()
{
    UserDefinedTypes instance;
    PrintPrivateMemberVariable(instance);
    return 0;
}