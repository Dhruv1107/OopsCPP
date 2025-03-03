#include <iostream>
#include <cstddef>  // For std::aligned_storage, alignof

struct MyStruct {
    alignas(16) char rand[16]; // Simulating a 16-byte type
    bool test;                 // 1-byte bool
};

int main() {
    std::cout << "Alignment of MyStruct: " << alignof(MyStruct) << " bytes" << std::endl;
    std::cout << "Size of MyStruct: " << sizeof(MyStruct) << " bytes" << std::endl;

    std::cout << "Size of rand: " << sizeof(MyStruct::rand) << " bytes" << std::endl;
    std::cout << "Size of test: " << sizeof(bool) << " bytes" << std::endl;

    return 0;
}

/*
Alignment of MyStruct: 16 bytes
Size of MyStruct: 32 bytes
Size of rand: 16 bytes
Size of test: 1 byte

    alignas(16) char rand[16] forces rand to be 16-byte aligned.
    bool test takes 1 byte.
    15 bytes of padding are added after bool to align MyStruct to 16 bytes.
    The total struct size becomes 32 bytes instead of 17.
*/
