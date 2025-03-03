// Curly brace v/s parenthesis and std::initializer_list
// Try searching : g++ initializer_list.h and check implementation on github
// https : // github.com/gcc-mirror/gcc/blob/master/libstdc%2B%2B-v3/libsupc%2B%2B/initializer_list

#include <iostream>
#include <vector>
#include <initializer_list>

struct UDT
{
    UDT()
    {
        std::cout << "Default Ctor\n";
    }

    UDT(int a, int b, int c)
    {
        std::cout << "Constructor with 3 params\n";
    }

    // UDT(std::initializer_list<int> data) : m_data(data)
    // {
    //     std::cout << "Initializer list Constructor\n";
    // }

    ~UDT()
    {
        std::cout << "Destructor called\n";
    }

    void PrintData()
    {
        for (auto e : m_data)
        {
            std::cout << e << " ";
        }
        std::cout << std::endl;
    }

private:
    std::initializer_list<int> m_data;
};

int main()
{
    // int a = 4;
    // int b(4);
    // int c{4}; //No issues

    // int d = 4.2;
    // int e(4.2);
    // // int f{4.2}; // error: narrowing conversion of '4.2000000000000002e+0' from 'double' to 'int' [-Wnarrowing]

    // std::vector<int> v{1, 2, 3}; // Initializes vector with 1,2,3. It uses initilaizer list

    // // std::vector<int> v1(1, 2, 3); // This is function signature, vector doesn;t have anything matching to this, So we get error

    // std::vector<int> v2(10, 1); // Size 10 vector initialized to 1

    // for (auto &i : v)
    // {
    //     std::cout << i << " ";
    // }
    // std::cout << std::endl;

    UDT x;          // default ctor will be called
    UDT u{1, 2, 3}; // Initializer list ctor will be called
    u.PrintData();

    UDT w(1, 2, 3); // 3 param ctor will be called
    w.PrintData();

    // Now suppoese if we remove initializer list ctor and do as follows:

    UDT y{1, 1, 1};
    y.PrintData();

    // What happens is compiler matches that with 3 params ctor and hence it is called, thus no erro

    return 0;
}