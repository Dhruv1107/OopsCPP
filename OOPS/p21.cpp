// Const Correctness with member functions
// const:
// read-only or immutable variable
    /*
        const float myNumber = 2.5f;
        myNumber = 2.6f; //Cant do this
    */
// read-only parameters
    /*
        void setValue(const float number) {
            // number = 123.f; // Cant do this
        }
        int main() {
            float myNumber = 2.5f;
            setValue(myNumber);
        }
    */
// making all of the member-variables in a member-functions read-only

#include <iostream>

class UserDefinedType
{
public:
    UserDefinedType() {}
    ~UserDefinedType() {}
    UserDefinedType(const UserDefinedType &rhs) {}

    int GetValue() const    // Anywhere in the member function we can't change the member variable m_value
    {
        ComputeValue();
        SetValue(1);
        return m_value;
    }

    void SetValue(int newValue) const // After adding const, the member variables are treated as const and hence error: assignment of member 'UserDefinedType::m_value' in read-only object
    {
        // m_value = newValue;
    }

    void ComputeValue() const
    {
        // m_value = 10;
    }

private:
    int m_value = 90;
};

const int con(int x) // const // we can't provide const keyword here as it is a non-member function
{
    x += 1;
    return x;
}

int main()
{
    UserDefinedType u;
    u.SetValue(100);

    const int y = con(6); // now y is read-only
    // y = 8;                // error: assignment of read-only variable 'y'

    std::cout << u.GetValue() << std::endl; // 90

    std::cout << con(6) << std::endl;   // 7 

    return 0;
}