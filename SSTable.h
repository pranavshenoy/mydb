#pragma once

#include <vector>
#include <map>
#include "context.h"
#include "MemTable.h"
using namespace std;
/*
structure

<key_size><key><val_size><val>

*/
class SSTable {
    // vector<uint8_t> buffer;
public:

    string path;
    
    /*
        <key>: offset in the sst
        using vector because the input elements will already be sorted and easy to do binary search
    */
    vector<pair<string, int>> index;
    //how many kv pairs per index?
    int sst_index_size;
    
    SSTable(shared_ptr<Context> context, string sst_file_path);
    bool flush(shared_ptr<MemTable> memTable);
    string Get(string key);
    
    
    // vector<uint8_t> get_buffer();
    
    //could be private
    static vector<uint8_t> convert_to_bytes(string key, string val);

    //Mainly used for testing
    // map<string, string> get_all_keys();
    
private:
    bool write(vector<uint8_t> data);

};