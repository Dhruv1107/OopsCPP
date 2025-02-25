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
        return data[idx];
    }

private:
    int *data;
};

int main()
{
    Collection myColection;
    myColection[0] = 1; // meaning: operator[] is called which performs
    // returns data[idx] i.e. data[0]. Finally it resolves to data[0] = 1; i.e. after this its normal assignment operator
    myColection[1] = 2;

    std::cout << myColection[1] << std::endl;
    return 0;
}