
#include "MemTable.h"

void MemTable::put(string key, string val) {
    memtable.insert({key, val});
}

string MemTable::get(string key) {
    if(memtable.find(key) == memtable.end()) {
        return "";
    }
    return memtable[key]; 
    
}