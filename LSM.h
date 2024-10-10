
#pragma once

#include "KVStoreInterface.h"
#include<map>

using namespace std;


class LSM : public KVStore {
map<string, string> memtable;
public:
    void put(string key, string val);
    string get(string key);

};