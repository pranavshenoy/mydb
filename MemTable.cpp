
#include "MemTable.h"
#include "SSTableManager.h"

void MemTable::put(string key, string val) {
    memtable.insert({key, val});
}

string MemTable::get(string key) {
    if(memtable.find(key) != memtable.end()) {
        return memtable[key];
    }
    return SSTableManager::GetInstance()->Get(key);
}