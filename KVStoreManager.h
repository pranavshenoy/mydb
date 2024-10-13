#pragma once

#include "KVStoreInterface.h"

class KVStoreManager {

public:
    KVStoreManager(unique_ptr<KVStore> new_store);
    void put(string key, string val);
    string get(string key);
private:
    unique_ptr<KVStore> store;
};