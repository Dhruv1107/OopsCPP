#include <iostream>
#include <string>
#include <vector>
#include <tuple>
using namespace std;
// Notes: 5. Dependency Inversion : https://docs.google.com/document/d/1yLvvo4x5vbk5fWhOmM9NjoYDDaIC-QwOY5n7FqxTc_Y/edit?tab=t.0#heading=h.n2d4ob2v4c6a
// 6. Dependency Injection: https://docs.google.com/document/d/1VzVSA1XRBNo5TTU8yqXI2nT-0WA4MBQeOBMsupUXiQ0/edit?tab=t.0#heading=h.u54kaokb9vt6

// A. High-level modules should not depend on low-level modules.
//    Both should depend on abstractions.
// B. Abstractions should not depend on details. 
//    Details should depend on abstractions.

enum class Relationship
{
  parent,
  child,
  sibling
};

struct Person
{
  string name;
};

struct RelationshipBrowser
{
  virtual vector<Person> find_all_children_of(const string& name) = 0;
};

struct Relationships : RelationshipBrowser // low-level
{
  vector<tuple<Person, Relationship, Person>> relations;

  void add_parent_and_child(const Person& parent, const Person& child)
  {
    relations.push_back({parent, Relationship::parent, child});
    relations.push_back({child, Relationship::child, parent});
  }

  vector<Person> find_all_children_of(const string &name) override
  {
    vector<Person> result;
    for (auto&& [first, rel, second] : relations)
    {
      if (first.name == name && rel == Relationship::parent)
      {
        result.push_back(second);
      }
    }
    return result;
  }
};

struct Research // high-level
{
  Research(RelationshipBrowser& browser)
  {
    for (auto& child : browser.find_all_children_of("John"))
    {
      cout << "John has a child called " << child.name << endl;
    }
  }
//  Research(const Relationships& relationships)
//  {
//    auto& relations = relationships.relations;
//    for (auto&& [first, rel, second] : relations)
//    {
//      if (first.name == "John" && rel == Relationship::parent)
//      {
//        cout << "John has a child called " << second.name << endl;
//      }
//    }
//  }
};

int main()
{
  Person parent{"John"};
  Person child1{"Chris"};
  Person child2{"Matt"};

  Relationships relationships;
  relationships.add_parent_and_child(parent, child1);
  relationships.add_parent_and_child(parent, child2);

  Research _(relationships);  // Dependency Injection
  /*
  The underscore (_) used in Research _(relationships); is just a variable name.
  In C++, every object must have a name unless it's an anonymous temporary object.
  */

  return 0;
}