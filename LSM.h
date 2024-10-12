
#pragma once

#include "KVStoreInterface.h"
#include<map>
#include "MemTable.h"

using namespace std;


class LSM : public KVStore {
MemTable* memtable;

public:
    LSM();
    void put(string key, string val);
    string get(string key);

};