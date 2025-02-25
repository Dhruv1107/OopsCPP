// mutable keyword to override const and the M&M rule
// It is used to make const values to be able to re-initialize
// It overrides const
// Refer: https://en.cppreference.com/w/cpp/language/cv

/*
class ThreadsafeCounter
{
    mutable std::mutex m; // The "M&M rule": mutable and mutex go together
    int data = 0;
public:
    int get() const //it makes sense as its a getter function and it should not modify any member variables.
    {
        std::lock_guard<std::mutex> lk(m); //But in multi-threaded we should acquire a lock, hence need to change the state of 'm' and thus need to make it mutable.
        return data;
    }

    void inc()
    {
        std::lock_guard<std::mutex> lk(m);
        ++data;
here we want the mutex to be mutable and the data to be const since we don't want to modify data(suppose) as we're defining get() function.
Since it is expected that in mult-threaded environment, the mutex will be changing states.
So this is one of the example of using mutable.
*/

#include <iostream>
#include <vector>

struct Point3f
{
public:
    explicit Point3f(float _x, float _y, float _z) : x(_x), y(_y), z(_z), w(1.0f) {}

    void ChangeW(float newW) const // adding const will make the member variables for this function as read-only. Thus we can't modify 'w' within this function
    {
        w = newW;
    }

    float x, y, z;
    mutable float w; // If we make it mutable, then we are allowed to modify 'w' in the ChangeW() function even after making it const
};