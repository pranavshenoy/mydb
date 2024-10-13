#include "TestWrites.h"
#include "../KVStoreManager.h"
#include "../LSM.h"
#include<iostream>
using namespace std;

// void KVStoreTests::test_writes() {

//     KVStore* store = new LSM();
//     KVStoreManager* manager = new KVStoreManager(store);
//     int i=0;
//     while(i < 100) {
//         manager->put(to_string(i), to_string(i));
//         i++;
//     }
//     i=0;
//     while(i < 100) {
//         string val = manager->get(to_string(i));
//         if(val.empty()) {
//             cout<<"Couldn't find value for key: "<<i<<endl;
//         }
//         i++;
//     }
// }


unordered_map<string, string> generate_test_input() {
    unordered_map<string, string> test_input;
    int i=0;
    while(i < 1000) {
        // test_input[to_string(i)] = to_string(i+rand()%1000);
        test_input[to_string(i)] = to_string(i);
        i++;
    }
    return test_input;
}

void KVStoreTests::test_writes() {

    unique_ptr<KVStore> store = make_unique<LSM>();
    KVStoreManager* manager = new KVStoreManager(std::move(store));
    auto test_input = generate_test_input();
    for(auto kv : test_input) {
        manager->put(kv.first, kv.second);
    }
    for(auto kv : test_input) {
        string val = manager->get(kv.first);
        if(val.compare(kv.second) == 0) {
            cout<<"Value matches for key: "<<kv.first<<" "<<kv.second<<endl;
        } else {
            cout<<"Value DOES NOT match for key: "<<kv.first<<" expected: "<<kv.second<<" actual: "<<val<<endl;
        }
    }

}