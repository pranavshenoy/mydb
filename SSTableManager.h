
#include<memory>
#include "MemTable.h"
#include <string>

using namespace std;

class SSTableManager {

    string sst_root_path;
    int file_id;
    SSTableManager(string root_path);
public:
    static shared_ptr<SSTableManager> GetInstance();
    bool FlushMemTable(shared_ptr<MemTable> memTable);
    bool write(string level, int file_id, vector<uint8_t> data);
};