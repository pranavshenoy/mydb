#include<string>
#include "KVStoreManager.h"
using namespace std;

KVStoreManager::KVStoreManager(KVStore* new_store) {
    store = new_store;
}

void KVStoreManager::put(string key, string val) {
    if(!store) {
        return;
    }
    store->put(key, val);
}

string KVStoreManager::get(string key) {
    return store->get(key);
}