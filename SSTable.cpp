
#include "SSTable.h"

SSTable::SSTable(map<string, string> memtable) {
    for(auto kv : memtable) {
        auto tmp_buffer = convert_to_bytes(kv.first, kv.second);
        buffer.insert(buffer.end(), tmp_buffer.begin(), tmp_buffer.end());
    }
}  

vector<uint8_t> SSTable::convert_to_bytes(string key, string val) {
    vector<uint8_t> buffer;
    uint8_t key_len = key.length();
    uint8_t val_len = val.length();
    buffer.push_back(key_len);
    buffer.insert(buffer.end(), key.begin(), key.end());
    buffer.push_back(val_len);
    buffer.insert(buffer.end(), val.begin(), val.end());
    return buffer;
}

map<string, string> SSTable::get_all_keys() {
    map<string, string> sst;
    int i=0;
    while(i < buffer.size()) {
        int key_len = (int)buffer[i];
        i++;
        if(i+key_len > buffer.size()) {
            //Error
            return {};
        }
        string key(buffer.begin() + i, buffer.begin() + i + key_len);
        i += key_len;

        int val_len = (int)buffer[i];
        i++;
        if(i+val_len > buffer.size()) {
            //Error
            return {};
        }
        string val(buffer.begin() + i, buffer.begin() + i + val_len);
        sst.insert({key, val});
        i += val_len;
    }
    return sst;
}