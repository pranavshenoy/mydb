
#include<memory>
#include "MemTable.h"

using namespace std;

class SSTableManager {

    SSTableManager();
public:
    static shared_ptr<SSTableManager> GetInstance();
    bool FlushMemTable(shared_ptr<MemTable> memTable);
};