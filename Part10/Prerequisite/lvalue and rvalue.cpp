// https://www.geeksforgeeks.org/lvalues-references-and-rvalues-references-in-c-with-examples/
// int i = 10;
// lvalue: something with a memory location
// rvalue: (on the right side of an assignment), does not point anywhere

/*
int a = 1;
int b = 2;
int c = (a+b); // rvalue = (a+b), lvalue = c
*/

/*
L value reference:
int& lvref = i; // Here int& denotes the alias

int i = 10;
int& ref= i;    //Here rhs is lvalue so int& ref is referring to l value
                // This works fine.

int& ref = 10;  // We get this error: cannot bind non-const lvalue reference of type int& to an rvalue of type int
                // Here with an lvalue reference we are referring to an rvalue

Note that in the above error message we only have non-const
When we declare the L value reference as const and point it to rvalue this should work since the compiler stores the r value
in some register in this case. you can check the compiler code in godbolt.org (or search for compiler explorer)

const int& ref = 10; //This works beacuse 10 will be some lvalue in the compiler or some temp variable

void setValueTo99(const int& changeMe) {
    changeMe = 99;  // We need to comment this line since you can't change the const
}
int main() {
    setValueTo99(10);   //this will also work since it is: const int& changeMe = 99;
    return 0;
}
*/

/*
R value reference:

int main() {
    int&& rvref = 10;
    cout<<rvref<<endl; //It prints 10
}

int main() {
    string s1 = "mike";
    string s2 = "a really long str";
    string&& s3 = s1+s2;
    cout<<s3<<endl;
}
*/