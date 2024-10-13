#include "../KVStoreManager.h"
#include "../LSM.h"
#include "TestWrites.h"
#include<iostream>
using namespace std;

int main() {

    KVStoreTests store_tests;
    store_tests.test_writes();
    return 0;
}