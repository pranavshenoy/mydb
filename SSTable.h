#include <vector>
#include <map>
using namespace std;
/*
structure

<key_size><key><val_size><val>

*/
class SSTable {
    vector<uint8_t> buffer;
public:
    SSTable(map<string, string> memtable);
    vector<uint8_t> get_buffer();
    

    //could be private
    static vector<uint8_t> convert_to_bytes(string key, string val);

    //Mainly used for testing
    map<string, string> get_all_keys();

    
};