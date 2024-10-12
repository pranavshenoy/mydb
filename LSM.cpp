#include "LSM.h"
#include<map>

using namespace std;

void LSM::put(string key, string val) {
    memtable->put(key, val);
}

LSM::LSM() {
    memtable = make_unique<MemTable>();
}
string LSM::get(string key) {
    return memtable->get(key);   
}