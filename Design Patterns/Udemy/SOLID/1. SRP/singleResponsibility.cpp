#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
// Notes Drive: https://docs.google.com/document/d/1OTIRfaoYo-glvv57SR1rv4OSzHM0oFeHJLWMDNTVEkM/edit?tab=t.0#heading=h.c3kb8e395t0i
struct Journal
{
  string title;
  vector<string> entries;

  explicit Journal(const string& title)
    : title{title}
  {
  }

  void add(const string& entry);

  // persistence is a separate concern
  void save(const string& filename);
};

void Journal::add(const string& entry)
{
  static int count = 1;
  entries.push_back(std::to_string(count++) + ": " + entry);

}

void Journal::save(const string& filename)
{
  ofstream ofs(filename);
  for (auto& s : entries)
    ofs << s << endl;
}

struct PersistenceManager
{
  static void save(const Journal& j, const string& filename)
  {
    ofstream ofs(filename);
    for (auto& s : j.entries)
      ofs << s << endl;
  }
};

int main()
{
  Journal journal{"Dear Diary"};
  journal.add("I ate a bug");
  journal.add("I cried today");

  //journal.save("diary.txt");

  PersistenceManager pm;
  pm.save(journal, "diary.txt");

  return 0;
}