#pragma once

#include "KVStoreInterface.h"

class KVStoreManager {

public:
    KVStoreManager(KVStore* new_store);
    void put(string key, string val);
    string get(string key);
private:
    KVStore* store;
};