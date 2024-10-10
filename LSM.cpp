#include "LSM.h"
#include<map>

using namespace std;

void LSM::put(string key, string val) {
    memtable.insert({key, val});
}

string LSM::get(string key) {
    if(memtable.find(key) == memtable.end()) {
        return "";
    }
    return memtable[key];    
}