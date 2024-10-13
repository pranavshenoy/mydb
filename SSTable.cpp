
#include "SSTable.h"
#include "MemTable.h"
#include "filesystem"
#include <fstream>
#include "context.h"

SSTable::SSTable(shared_ptr<Context> context, string sst_file_path) {
    this->path = sst_file_path;
    this->sst_index_size = context->sst_index_size;
}  

bool SSTable::write(vector<uint8_t> data) {
    
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


bool SSTable::flush(shared_ptr<MemTable> memTable) {
    vector<uint8_t> buffer;
    int i = 0;
    for(auto kv : memTable->memtable) {
        auto tmp_buffer = convert_to_bytes(kv.first, kv.second);
        buffer.insert(buffer.end(), tmp_buffer.begin(), tmp_buffer.end());
        if(i % sst_index_size == 0) {
            index.push_back({kv.first, i});
        }
        i++;
    }
    if(!write(buffer)) {
        index.clear();
        return false;
    }
    return true;
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

pair<int, int> SSTable::GetOffsetRange(string key) {
    if(index.empty()) {
        return {-1, -1};
    }
    if(key.compare(index[0].first) < 0) {
        return {-1, -1};
    }
    for(int i=1; i<index.size();i++) {
        string curr = index[i].first;
        if(key.compare(curr) < 0) {
            return {index[i-1].second, index[i].second};
        }
    }
    return {-1, -1};
}

vector<uint8_t> SSTable::ReadFromFile(int start, int byte_count) {


}

string SSTable::GetValue(string key, vector<uint8_t> data) {

}


string SSTable::Get(string key) {

    auto offset = GetOffsetRange(key);
    if(offset.first == -1 || offset.second == -1) {
        return "";
    }
    auto data = ReadFromFile(offset.first, offset.second - offset.first);
    return GetValue(key, data);
}

// map<string, string> SSTable::get_all_keys() {
//     map<string, string> sst;
//     int i=0;
//     while(i < buffer.size()) {
//         int key_len = (int)buffer[i];
//         i++;
//         if(i+key_len > buffer.size()) {
//             //Error
//             return {};
//         }
//         string key(buffer.begin() + i, buffer.begin() + i + key_len);
//         i += key_len;

//         int val_len = (int)buffer[i];
//         i++;
//         if(i+val_len > buffer.size()) {
//             //Error
//             return {};
//         }
//         string val(buffer.begin() + i, buffer.begin() + i + val_len);
//         sst.insert({key, val});
//         i += val_len;
//     }
//     return sst;
// }

// vector<uint8_t> SSTable::get_buffer() {
//     return buffer;
// }