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
    i=0;
    while(i < 100) {
        string val = manager->get(to_string(i));
        if(val.empty()) {
            cout<<"Couldn't find value for key: "<<i<<endl;
        }
        i++;
    }
}