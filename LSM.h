
#pragma once

#include "KVStoreInterface.h"
#include<map>
#include "MemTable.h"

using namespace std;


class LSM : public KVStore {
shared_ptr<MemTable> memtable;

// in number of KV pairs. can be changed into total bytes too!
int memtable_size;

public:
    LSM();
    void put(string key, string val);
    string get(string key);

};