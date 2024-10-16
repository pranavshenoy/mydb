#include "LSM.h"
#include<map>
#include "SSTableManager.h"

using namespace std;

LSM::LSM() {
    memtable = make_shared<MemTable>();
    context = make_shared<Context>();
    memtable_size = context->memtable_size; 
}

void LSM::put(string key, string val) {
    memtable->put(key, val);
    if(memtable->memtable.size() >= memtable_size) {
        //should be asynchronous
        bool flushed = SSTableManager::GetInstance()->FlushMemTable(context, memtable);
        if(flushed) {
            memtable.reset();
            memtable = make_shared<MemTable>();
        }
    }
}

string LSM::get(string key) {
    return memtable->get(key);   
}