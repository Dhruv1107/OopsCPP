#include <iostream>

int foo(int x)
{
    x = x + 1;

    return x;
}

void f(int *p)
{
    std::cout << "in f()" << std::endl;
    // std::cout << p << std::endl;
    std::cout << "*p: " << *p << std::endl;
    std::cout << "p[0]: " << p[0] << std::endl;
    std::cout << "p[1]: " << p[1] << std::endl;
    std::cout << "out f()" << std::endl;
}

int main()
{
    int a;

    int *arr = new int[10];

    arr[9] = 8;

    f(arr + 9);
    std::cout << arr << std::endl;

    std::cout << "*arr+9: " << (*(arr + 9)) << std::endl;

    delete[] arr;
    // a = 9;

    // a = foo(a);

    // std::cout << a << std::endl;

    return 0;
}