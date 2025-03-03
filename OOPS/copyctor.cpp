// Example showing how copy ctor infinitely calls itself when it is implemented as pass by value

#include <iostream>

// void foo(ex o);

class ex
{
public:
    static int cnt;
    ex(int v)
    {
        std::cout << "Default Constructor called" << std::endl;
        value = v;
    }

    ex(ex &rhs)
    {
        cnt++;
        std::cout << "Copy Ctor cnt: " << cnt << std::endl;
        value = rhs.value;
        // foo(rhs); // copy ctor call, removing this will not call ctor again and again
        // Becaues before going into foo we should be ready to have the
    }

    ~ex()
    {
        std::cout << "Destructor called" << std::endl;
    }

    // ex &operator=(ex rhs)
    // {
    //     value = rhs.value;
    //     return *this;
    // }
    void foo(ex ob) // here copy ctor will get stuck in infinite loop, we'll never reach next line, Use debugger and see we never called foo, we were stuck in only creating the object
    {
        std::cout << "In foo" << std::endl;
    }

    void get()
    {
        std::cout << value << std::endl;
    }

    int value;
};

int ex::cnt = 0;

int main()
{
    ex o1(12);

    ex o2 = o1; // call to copy ctor

    o2.foo(o1); // This is also copy ctor call, hence before going to foo, we need to go to the copy ctor definition

    // What happens here is before calling foo() we need to create its parameter
    // Once the paramater is created then only we can enter the inside body of foo()
    // Here the parameter is an object
    // that parameter needs to be initialized with o1
    // Thus first we need to create the parameter of foo() with o1
    // Hence before calling foo(), we'll call copy ctor
    // and if we have foo() again in copy ctor
    // we'll get stuck in caliing copy ctor again and again
    // and only able to exit when we get segmentation fault
    // To avoid this we pass object to be copied by copy ctor with '&'
    // Since it never need to modify the passed object, we make it const

    // o1.foo(o1);

    // ex o2 = o1;

    // o1.get();
    // o2.get();

    return 0;
}

/*
When you call a function with parameters in C++, the parameters are created (or initialized) before the function execution begins. Here’s a detailed breakdown of how this process works:

### 1. **Function Call Initiation**

When a function call is made, such as:

```cpp
int result = myFunction(5, 10);
```

### 2. **Parameter Evaluation**

- **Expression Evaluation**: Before the function is called, the expressions used as arguments are evaluated. In this case, the integers `5` and `10` are evaluated.
- **Temporary Objects**: If any of the arguments are complex types (like objects), temporary objects may be created and initialized before the function call. For instance:

  ```cpp
  MyClass obj;
  int result = myFunction(obj); // obj is created before myFunction is called
  ```

### 3. **Parameter Passing**

- **Copying Arguments**: Once the arguments are evaluated and ready, they are passed to the function. This can happen in different ways, depending on how the function is defined:
  - **By Value**: The values are copied into the function's parameters.
  - **By Reference**: The function receives references (or pointers) to the original arguments, avoiding a copy.

For example:
```cpp
void myFunction(int a, int& b) {
    // Function body
}
```
Here, `a` is passed by value, and `b` is passed by reference.

### 4. **Function Execution**

- **Function Call**: After the parameters are prepared, the function call is executed. The control is transferred to the function, and the function body begins execution with the provided parameters.

### 5. **Returning from the Function**

- After the function executes and returns, any temporary objects created for the arguments (if applicable) are destroyed, and control returns to the caller.

### Example Scenario

Consider the following code:

```cpp
#include <iostream>

void display(int x, int y) {
    std::cout << "x: " << x << ", y: " << y << std::endl;
}

int main() {
    int a = 5;
    int b = 10;
    display(a, b); // Parameters a and b are evaluated before the function is called
    return 0;
}
```

### Breakdown of Execution

1. **Evaluate Arguments**: The values of `a` and `b` (5 and 10) are evaluated.
2. **Function Call**: Control transfers to `display()`, where:
   - A copy of `5` is passed to `x`.
   - A copy of `10` is passed to `y`.
3. **Execute Function**: The function executes and prints the values.

### Conclusion

In summary, the parameters are evaluated and prepared before the function is called. This process ensures that the function has the correct values to work with when execution begins. Understanding this sequence is crucial for effective function usage and for managing resource lifetimes in C++.

*/

/*
Sure! Let’s delve deeper into the creation and management of temporary objects when calling functions with parameters in C++. This involves understanding how the compiler handles arguments, especially for complex types such as objects.

### 1. **What Are Temporary Objects?**

Temporary objects are instances of classes that are created to hold values during the execution of expressions, particularly when passing arguments to functions. They are created when:
- You pass an object by value to a function.
- You use an expression that results in an object.

### 2. **Creation of Temporary Objects**

When you call a function with an object as an argument, the following steps typically occur:

#### a. **Argument Evaluation**

- The compiler evaluates the arguments passed to the function. If the argument is an object (or a complex type), and you are passing it by value, a temporary object may be created.

#### b. **Constructor Call**

- If a temporary object is created, the constructor of the object is called to initialize it. For example:

  ```cpp
  class MyClass {
  public:
    //   MyClass(int value) { /* initialization code */
//}
// Other members...
// }
// // ;
//     void myFunction(MyClass obj) { /* function code */ }

// int main()
// {
//     myFunction(MyClass(10)); // Temporary object created here
// }
//   ```

//   In this example, `MyClass(10)` creates a temporary object of type `MyClass`, initialized with the value `10`.

// ### 3. **Lifetime of Temporary Objects**

// - **Scope and Lifetime**: Temporary objects typically exist until the end of the full expression in which they were created. In the previous example, the temporary `MyClass` object created during the function call exists for the duration of the `myFunction` call and is destroyed immediately after the function returns.
// - **Destruction**: After the function call completes, the destructor of the temporary object is invoked, releasing any resources it might hold.

// ### 4. **Return Value Optimization (RVO)**

// To enhance performance, C++ compilers often employ Return Value Optimization (RVO) and Named Return Value Optimization (NRVO). These optimizations can eliminate unnecessary temporary objects:

// #### a. **RVO Example**

// If a function returns an object, the compiler can construct the object directly in the caller's context, avoiding the creation of a temporary object:

// ```cpp
// MyClass createObject()
//   {
//       return MyClass(20); // Without RVO, a temporary would be created here
//   }

//   int main()
//   {
//       MyClass obj = createObject(); // With RVO, no temporary is created
//   }
// ```

// ### 5. **Copy Elision**

// C++ allows for "copy elision," where the compiler can optimize away the copying of temporary objects under certain conditions, further enhancing performance:

// - **Copy Elision Example**:

// ```cpp
// class MyClass
// {
// public:
//     MyClass() { /* constructor code */ }
//     MyClass(const MyClass &) { /* copy constructor code */ } // Not called if copy elision occurs
// };

// void myFunction(MyClass obj) { /* function code */ }

// int main()
// {
//     MyClass temp;
//     myFunction(temp); // No temporary object created if copy elision is applied
// }
// ```

//     ## #6. *
//     *Passing by Reference **

//         To avoid the overhead of creating temporary objects,
//     you can pass objects by reference or use smart pointers :

// ```cpp void myFunction(const MyClass &obj)
// { /* function code */
// }
// ```

//     - In this case,
//     no temporary object is created.The function operates directly on the original object.

//         ## #7. *
//         *Implications of Temporary Objects * *

//         -**Performance **: Creating temporary objects incurs overhead (constructor/destructor calls). Passing by reference can improve performance for large objects.
// - **Const Correctness**: When passing objects by const reference, you ensure that the function cannot modify the original object while avoiding the cost of copying.

// ### Conclusion

// Temporary objects play a significant role in C++ function calls, particularly when dealing with complex types. Understanding their lifecycle—from creation through destruction—helps developers optimize performance and manage resources effectively. By leveraging techniques like pass-by-reference and copy elision, you can minimize the overhead associated with temporary objects in your code.
// */

/*
In the context of C++ function calls, the temporary object created as an argument and the parameter `obj` within the function are distinct objects. Here's a detailed explanation of their relationship:

### 1. **Temporary Object Creation**

When you pass an argument like `MyClass(42)` to a function:

- A **temporary object** is created on the stack (or in a register) when the expression is evaluated. This object is an instance of `MyClass`, initialized by its constructor.

### 2. **Copying the Temporary Object**

- When the function is called (e.g., `myFunction(MyClass(42));`), the function parameter `obj` receives a **copy** of the temporary object.
- If `MyClass` has a copy constructor, this constructor is invoked to create a copy of the temporary object. If not, the compiler provides a default copy constructor that performs a member-wise copy.

### 3. **Lifecycle and Distinction**

- The **temporary object** exists only for the duration of the function call, and it will be destroyed after the full expression in which it was created completes. This means it's destroyed right after the function call returns.
- The parameter `obj`, however, is a separate object that is created as a result of the copy operation. Its lifetime extends until the function `myFunction` returns.

### 4. **Illustration of the Process**

Consider this code example:

```cpp
#include <iostream>

class MyClass {
public:
    MyClass(int val) : value(val) {
        std::cout << "Constructor called for value: " << value << std::endl;
    }

    MyClass(const MyClass& other) : value(other.value) {
        std::cout << "Copy constructor called for value: " << value << std::endl;
    }

    ~MyClass() {
        std::cout << "Destructor called for value: " << value << std::endl;
    }

    int value;
};

void myFunction(MyClass obj) {
    std::cout << "Inside myFunction with obj value: " << obj.value << std::endl;
}

int main() {
    myFunction(MyClass(42)); // Temporary created and passed by value
    return 0;
}
```

### Output Breakdown

1. **Constructor Called**: When `MyClass(42)` is evaluated, the constructor is called, and the temporary object is created.
2. **Copy Constructor Called**: The copy constructor is invoked to create `obj` within `myFunction`.
3. **Function Execution**: The function uses `obj`.
4. **Destructor Called for `obj`**: After `myFunction` returns, the destructor for `obj` is called.
5. **Destructor Called for Temporary**: Finally, the destructor for the temporary object is called.

### Conclusion

In summary, while the temporary object and the function parameter `obj` may contain the same value, they are different objects. The temporary exists only until the end of the full expression (the function call), while `obj` lives for the duration of the function. This distinction is crucial for understanding object lifetimes and resource management in C++.
*/