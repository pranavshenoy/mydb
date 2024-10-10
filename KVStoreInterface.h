#pragma once

#include<string>
using namespace std;

class KVStore {
    public:
    virtual void put(string key, string val) = 0;
    virtual string get(string key) = 0;
};