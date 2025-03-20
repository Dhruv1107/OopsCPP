#include <string>
#include <iostream>
#include <memory>

using namespace std;
struct Address
{
  string street;
  string city;
  int suite;
  Address(const string& street, const string& city, const int suite)
  : street{street},
    city{city},
    suite{suite}
    {
    }

    Address(const Address& other)
    : street{other.street},
      city{other.city},
      suite{other.suite}
    {
    }

    friend ostream& operator<<(ostream& os, const Address& obj)
    {
      return os
        << "street: " << obj.street
        << " city: " << obj.city
        << " suite: " << obj.suite;
    }
};

struct Contact
{
  string name;
  Address* address;

  Contact(string name, Address* address)
  : name{name}, address{address}
    {
    }

  Contact(const Contact& other)
  : name{other.name}
  , address{ new Address{*other.address} }  // other.address is a pointer so deference it.
  {
  }
  friend ostream& operator<<(ostream& os, const Contact& obj)
  {
    return os
      << "name: " << obj.name
      << " works at " << *obj.address; // note the star here
  }
};

struct EmployeeFactory {
    static unique_ptr<Contact> new_main_office_employee
    (const string& name, const int suite) {
        static Contact p{"", new Address{"123 East Dr", "London", 0}};
        return new_employee(name,suite,p);
    }

    private:
    static unique_ptr<Contact> new_employee(const string& name, const int suite, const Contact& prototype) {
        auto result = make_unique<Contact>(prototype);
        result->name = name;
        result->address->suite = suite;
        return result;
    }
};
int main() {
  auto john = EmployeeFactory::new_main_office_employee("John",123);
  cout<<*john<<endl;
}

  
  