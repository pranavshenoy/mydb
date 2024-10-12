
#include <map>
#include <string>
using namespace std;

class MemTable {

public: 
    //TODO: can it hold same key multiple times? I don't think so. Is it needed?
    //setting it to public so that SSTable can access it
    map<string, string> memtable;
    void put(string key, string val);
    string get(string key);
};