// Caution: Multiple Inheritance (and example of using it)
// We'll use struct as its just class with everything public
// https://www.geeksforgeeks.org/multiple-inheritance-in-c/
#include <iostream>

struct nocopy
{
    nocopy() {};
    nocopy(const nocopy &rhs) = delete; // Delete the cpy constructor
    nocopy &operator=(const nocopy &rhs) = delete;  // Delete the cpy assignment constructor
};
struct Dog : public nocopy  // We can't use copy and copy assignment constructor
{
    virtual void Bark()
    {
        std::cout << "Dog::Bark\n";
    }
};

struct Golden : public Dog
{
    virtual void Bark() override
    {
        std::cout << "Golden::Bark()\n";
    }
};

struct BorderCollie : public Dog
{
    virtual void Bark() override
    {
        std::cout << "BorderCollie::Bark()\n";
    }
};

struct Coltriever : public Golden, BorderCollie
{
    void Bark() override
    {
        std::cout << "Coltriever::Bark()\n";
    }
};

int main()
{
    // Compile Time
    // Dog d;
    // Golden g;
    // BorderCollie bc;
    // Coltriever c;

    // d.Bark();
    // g.Bark();
    // bc.Bark();
    // c.Bark();

    // Run Time

    // Dog *d = new Dog;
    // Dog *g = new Golden;
    // Dog *bc = new BorderCollie;
    // Dog *c = new Coltriever; // error: 'Dog' is an ambiguous base of 'Coltriever' due to multiple inheritance
    // of Coltriever between Golden and BorderCollie, the compiler cannot decide which Bark() to assign to Coltriever
    // this is the caution with multiple inheritance
    // To fix do: Coltriever* c = new Coltriever

    // d->Bark();
    // g->Bark();
    // bc->Bark();
    // c->Bark();

    // Experiment with deleting copy const and copy assignment

    // Dog d;
    // Dog d2;

    // d = d2;  // We can't do this since we have deleted copy assignment constructor

    // Dog d3 = d2; // We can't do this since we have deleted copy constructor

    // Dog* d4 = new Dog;
    // Dog* golden = new Golden;
    // dog = golden; // This is possible since we are just changing the pointers and not calling the copy constructor

    return 0;
}