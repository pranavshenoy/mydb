
#pragma once

#include<memory>
#include "MemTable.h"
#include <string>
#include "context.h"
#include "SSTable.h"

using namespace std;

class SSTableManager {

    string sst_root_path;
    int file_id;
    vector<shared_ptr<SSTable>> sstInMemoryIndex;
    string GetUniqueFilePath(string level);
    shared_ptr<Context> context;
public:
    
    SSTableManager(shared_ptr<Context> context);
    static shared_ptr<SSTableManager> GetInstance();
    bool FlushMemTable(shared_ptr<Context> context, shared_ptr<MemTable> memTable);
    string Get(string key);
};