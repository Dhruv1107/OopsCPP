// Copy Constructors

// Questions: How constructor works bts and are they responsible for object storage allocation etc?
// Ans: Constructors are called by compiler whenever we declare an object. They are responsible for initialisation
// of any or none member variables. These are the special member functions 'constructing' the object.
// The compiler allocates the memory to object based on the class blueprint

#include <iostream>
#include <string>

class myArray
{

public:
    myArray()
    {

        std::cout << "Default Constructor" << std::endl;
        data = new int[10];

        for (int i = 0; i < 10; i++)
        {
            data[i] = i * i;
        }
    }

    ~myArray()
    {
        std::cout << "deleting: " << data << std::endl;
        delete[] data;
    }

    // Own Copy Constructor
    myArray(const myArray &rhs)
    {
        std::cout << "Copy Constructor" << std::endl;
        data = new int[10]; // initialising the 'data' for this new object (i.e. on LHS)

        for (int i = 0; i < 10; i++)
        {
            data[i] = rhs.data[i]; // doing deep copy
        }
        // If it was shallow copy then:
        /*
        data = rhs.data;
        and that's all
        This is how two objects are holding pointer to same memory location
        which is the case in the default copy constructor
        */
    }

    // Copy Assignment Operator
    // Called when object is already created, we are just making a copy later (e.g. a2 = a1)
    myArray &operator=(const myArray &rhs)
    {

        std::cout << "Copy Assignment Operator" << std::endl;
        // Self-assignment check
        if (&rhs == this) // when suppose a2 = a2, doesn't make sense, so do nothing and simply return current object
        {
            return *this;
        }

        // perfrom copy of the values in this object i.e. on lhs from rhs
        delete[] data;      // deleting this object's previous data and allocating new data for this object
        data = new int[10]; // Initilizing the new memory for the data in this object

        for (int i = 0; i < 10; i++)
        {
            data[i] = rhs.data[i];
        }

        return *this; // Need to return the new object i.e. on lhs;
    }

    void printArray()
    {
        for (int i = 0; i < 10; i++)
        {
            std::cout << data[i] << std::endl;
        }
    }

    void setData(int index, int value)
    {
        data[index] = value;
    }

private:
    int *data;
};

int main()
{
    // Std. case example
    std::string mike = "mike"; // String is a class and 'mike' is the object
    // here the default constructor will be called for string class

    std::string mike2 = mike; // Copy of object 'mike' is done into object 'mike2'. Here '=' acts as copy-assignment operator
    // which we also get as default from compiler apart from default constructor(s) and detructor
    // Note: The default copy constructor gives us shallow copy.

    std::cout << mike << std::endl;
    std::cout << mike2 << std::endl;

            /* Copy Constructor example
            class Vector3{
            public:
                float x,y,z;
            };
            int main() {
                Vector3 m;
                m.x - 1.0f;
                m.y = 2.0f;
                m.z = 3.0f;
                Vector3 m2;
                m2 = m; //copy-assignment operator

                cout<<m2.x<<m2.y<<m2.z; // 1,2,3
            }

            */

    // Another Example
    myArray a1;
    // a1.printArray();
    a1.setData(0, 500);
    a1.setData(1, 200);

    myArray a2 = a1; // This will give double free as default copy constructor does shallow copy. Copying the same pointer in both the objects.
    // To handle this, do deep copy. For this need to implement own copy constructor and handle this issue.
    // Here a1 is the rhs in the copy constructor parameter
    // a2.printArray();

    myArray a3;

    a3 = a2; // Copy Assignmet operator is called

    a1.printArray();
    a2.printArray();
}