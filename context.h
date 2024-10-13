
#pragma once
#include <string>
using namespace std;
/*
contains all info for configuring the kvstore

*/
class Context {

public:
    //number of kv pairs
    int memtable_size = 100;
    int sst_index_size = 10;
    string sst_root_path = "/Users/prsheno/work/mydb/.sst/";
};