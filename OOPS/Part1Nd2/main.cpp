#include "Student.hpp"

int main() {
    Student mike;
    mike.m_name = "mike s";
    mike.printName();

    Student Sue;
    Sue.m_name = "Sue";
    Sue.printName();

    Student Dhruv("dhruv");
    Dhruv.printName();
    // Destructor will be called for Sue first and then mike
    // It follows like popping up from stack

    return 0;
}