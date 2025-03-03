// Class Data layout (Optimizing for size)

// The compiler will byte align the object created based on the biggest data type, moslty in powers of 2 or 4 for performance reasons
// This is called padding by adding empty bytes
#include <iostream>
#include <string>

struct GameState {
    bool checkpoint;
    float score;
    short numberOfPlayers;
};

// struct GameState {   // You can rearrange the struct members with largest member at start to save the memory
//     float score;     // Change this to double and observe the results of alignof, explaination is given below
//     short numberOfPlayers;
//     bool checkpoint;
// };

int main() {
    GameState gs;

    std::cout << alignof(gs) << std::endl;
    std::cout << sizeof(gs.checkpoint) << std::endl;
    std::cout << sizeof(gs.score) << std::endl;
    std::cout << sizeof(gs.numberOfPlayers) << std::endl;
    std::cout << sizeof(gs) << std::endl;

    return 0;
}

/*
    the memory layout of the GameState structure, focusing on padding and alignment.

    bool checkpoint → 1 byte
    Followed by 3 bytes of padding (to align float on a 4-byte boundary)
    float score → 4 bytes
    short numberOfPlayers → 2 bytes
    Followed by 2 bytes of padding (to align the structure to a multiple of 4 bytes)
    Total size of GameState: 12 bytes

    This is verified in the program output:
    1
    4
    2
    12

    The padding ensures proper alignment for efficient memory access.
*/

/*
    Rearranged Structure:
        struct GameState {
            float score;
            short numberOfPlayers;
            bool checkpoint;
        };

    Memory layout:
        float score → 4 bytes (naturally aligned)
        short numberOfPlayers → 2 bytes
        bool checkpoint → 1 byte
        1 byte padding (to align structure size to 4 or 8 bytes)
        Total size: 8 bytes
*/

/*
    Key Takeaways:
        Padding is automatically added by the compiler to ensure proper memory alignment for efficient access.
        Placing smaller data types together reduces padding and results in a smaller structure size.
        Optimized ordering can save memory, which is crucial in memory-constrained environments (e.g., embedded systems).
        The largest member’s alignment often dictates the struct’s final size.
    By grouping members of similar sizes together, you can minimize padding and make the structure more memory efficient.
*/

/*
    The alignof operator in C++ (introduced in C++11) returns the alignment requirement of a type.
    The alignment of a type is the number of bytes required for the data to be stored at a memory location that is efficiently accessible by the CPU.

    struct GameState {
        float score;
        short numberOfPlayers;
        bool checkpoint;
    };

    alignof(gs) => would return 4and the total size of struct is 8.
   
    But if we change the float to double then the alignof would return 8 and the total size of struct would be 16.

    alignof(gs): 8
        The alignment requirement for gs is 8 bytes because double (the largest data type) requires 8-byte alignment.
    sizeof(gs.score): 8
        double takes 8 bytes.
    sizeof(gs.numberOfPlayers): 2
        short takes 2 bytes.
    sizeof(gs.checkpoint): 1
        bool takes 1 byte.
    sizeof(gs): 16
        The compiler adds padding to align the structure to an 8-byte boundary:
            double (8 bytes) is naturally aligned.
            short (2 bytes) follows, but 5 bytes of padding are added after bool to make the total size 16 byte

    Larger data types determine structure alignment.
    
*/
