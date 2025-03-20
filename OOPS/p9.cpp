// Resource Acquisition Is Initialization (RAII)
// It is a C++ programming technique which binds the lifecycle of a resource that must be acquired before use (aloocated heap memory, thread of execution,
// open socket, open file, locked mutex, disk space, database connection--anything that exists in limited supply) to the lifetime of an object.
// Refer: https://en.cppreference.com/w/cpp/language/raii
// Refer: https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#e6-use-raii-to-prevent-leaks
// Brief Idea: RAII is about acquiring all resources in constructor and freeing all of them in destructor

#include <iostream>

class Collection
{
public:
    Collection()
    {
        data = new int[10];
        for (int i = 0; i < 10; i++)
        {
            data[i] = i;
        }
    }

    ~Collection()
    {
        delete[] data;
    }

    int &operator[](std::size_t idx)
    {
        std::cout << "Here!" << std::endl;
        return data[idx];
    }

    const int &operator[](std::size_t idx) const
    {
        std::cout << "Const Here!" << std::endl;
        return data[idx];
    }

private:
    int *data;
};

int main()
{
    Collection myColection;
    myColection[0] = 100; // meaning: operator[] is called which performs
    // returns data[idx] i.e. data[0]. Finally it resolves to data[0] = 1; i.e. after this its normal assignment operator
    myColection[1] = 200;

    std::cout << myColection[1] << std::endl;

    /*
        The non-const operator[] is called instead of the const operator[] because the object myColection is not a const object.
        In C++, the version of the operator[] that gets called depends on the const-qualification of the object on which it is called.
    */

    const Collection myColection1;
    std::cout << myColection1[1] << std::endl; // Calls const operator[]
    return 0;
}