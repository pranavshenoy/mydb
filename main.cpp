#include "KVStoreManager.h"
#include "LSM.h"
#include<iostream>
using namespace std;

void test() {

    KVStore* store = new LSM();
    KVStoreManager* manager = new KVStoreManager(store);
    int i=0;
    while(i < 1000) {
        manager->put(to_string(i), to_string(i));
        i++;
    }
    i = 0;
    while(i<10) {
        std::cout<<manager->get(to_string(i))<<std::endl;
        i++;
    }

}


int main() {

    test();
    return 0;
}