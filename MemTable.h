
#include <map>
#include <string>
using namespace std;

class MemTable {

    map<string, string> memtable;

public: 
    void put(string key, string val);
    string get(string key);
};