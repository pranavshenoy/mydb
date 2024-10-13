#include "SSTableManager.h"
#include "SSTable.h"
#include <fstream>


SSTableManager::SSTableManager(shared_ptr<Context> context) {
    //Not handling crash recovery!
    //TODO: remove all files 
    filesystem::path root(context->sst_root_path);
    //TODO: handle exception
    filesystem::remove_all(root);
    filesystem::create_directory(context->sst_root_path);
    sst_root_path = context->sst_root_path;
    file_id  = 0;
}

shared_ptr<SSTableManager> SSTableManager::GetInstance() {
    /*
    TODO: this needs to come from LSM file but for now since the configs are static, it should be fine
    */ 
    shared_ptr<Context> context = make_shared<Context>();
    static shared_ptr<SSTableManager> sstManager = make_shared<SSTableManager>(context);
    return sstManager;
}

string SSTableManager::GetUniqueFilePath(string level) {
    this->file_id++; //NOT thread safe!
    string dir = sst_root_path + "/" + level;
    string file_path = dir + "/"+ to_string(file_id);
    filesystem::create_directories(dir);
    return file_path;
}

bool SSTableManager::FlushMemTable(shared_ptr<Context> context, shared_ptr<MemTable> memTable) {

    string sst_file_path = GetUniqueFilePath("l1");
    shared_ptr<SSTable> sst = make_shared<SSTable>(context, sst_file_path);
    if(!sst->flush(memTable)) {
        return false;
    }
    sst_list.push_back(sst);
    return true;
}

string SSTableManager::Get(string key) {
    
    for(int i=sst_list.size()-1; i>= 0;i-- ) {
        string val = sst_list[i]->Get(key);
        if(!val.empty()) {
            return val;
        }
    }
    return "";
}