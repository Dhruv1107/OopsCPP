#include <string>
class IntArray
{
public:
    // The Big 3
    //(1) Constructor
    IntArray(std::string name);
    //(2) Destructor
    ~IntArray();
    //(3) Copy constructor policy
    IntArray(const IntArray &rhs);
    //(3.1) Copy assignment operator policy
    IntArray &operator=(const IntArray &rhs);
    // The other 2 (in total, making 'The Big 5')
    // Move Constructor policy
    IntArray(IntArray &&source);
    // Move assignment operator policy
    IntArray &operator=(IntArray &&source);

private:
    std::string m_name;
    int *m_data;
};