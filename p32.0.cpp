// The 'static' keyword - understanding static vs stack vs heap memory
#include <iostream>

void foo() {
    static int s_variable = 0;  //Initialize only once also the scope is only in foo() function
    s_variable+=1;
    std::cout<<s_variable<<std::endl;
}
int main() {

    int x = 0; // x is a local variable

    int* p = new int; // p is a local variable
                      // p points to memory
                      // allocated on the heap
                      // The memory on the
                      // heap leaves until we 
                      // say so.

    delete p; // Free the allocated memory

    for(int i=0;i<10;i++) {
        foo(); //This will print 1 to 10
    }

    // s_variable = 10;    // This will return an error
    return 0;
}

/*
Memory Segments in C++:
    Stack: Stores local variables and function call frames.
    Heap: Stores dynamically allocated memory using new.
    Static Memory: Stores static/global variables in the binary.
*/

/*
Memory Allocation in the Code:
    x is stored in the stack.
    s_variable is stored in static memory (inside the binary).
    p is stored in the stack, but it points to memory allocated on the heap.
    The new int call allocates 4 bytes (assuming int is 4 bytes) in the heap.
    delete p deallocates the memory from the heap.
*/

/*
You can use objdump tool in linux to display the info from object files
*/
