#include "TestWrites.h"
#include "../KVStoreManager.h"
#include "../LSM.h"
#include<iostream>
using namespace std;

void KVStoreTests::test_writes() {

    KVStore* store = new LSM();
    KVStoreManager* manager = new KVStoreManager(store);
    int i=0;
    while(i < 100) {
        manager->put(to_string(i), to_string(i));
        i++;
    }
}