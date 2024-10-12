#include "SSTableManager.h"
#include "SSTable.h"
#include <fstream>


SSTableManager::SSTableManager(string root_path) {
    //Not handling crash recovery!
    //TODO: remove all files 
    filesystem::path root(root_path);
    //TODO: handle exception
    filesystem::remove_all(root);
    filesystem::create_directory(root_path);
    sst_root_path = root_path;
    file_id  = 0;
}

shared_ptr<SSTableManager> SSTableManager::GetInstance() {
    static shared_ptr<SSTableManager> sstManager = make_shared<SSTableManager>("/Users/prsheno/work/mydb/.sst/");
    return sstManager;
}

bool SSTableManager::write(string level, int file_id, vector<uint8_t> data) {
    string dir = sst_root_path + "/" + level;
    filesystem::create_directories(dir);
    string path = dir + "/" + to_string(file_id); //can be removed if fs_path can be used for ostream
    filesystem::path fs_path(path);
    ofstream ostream(path, std::ios::binary);
    if(!ostream) {
        return false;
    }
    ostream.write(reinterpret_cast<const char*>(data.data()), data.size());
    if(ostream.bad()) {
        filesystem::remove(fs_path);
        ostream.close();
        return false;
    }
    ostream.close();
    return true;
}

bool SSTableManager::FlushMemTable(shared_ptr<MemTable> memTable) {

    shared_ptr<SSTable> sst = make_shared<SSTable>(memTable->memtable);
    this->file_id++; //NOT thread safe!
    if(!write("l1", file_id, sst->get_buffer())) {
        return false;
    }
    return true;
}