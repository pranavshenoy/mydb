
// #include "../SSTable.h"
// #include "cassert"
// #include<iostream>
// using namespace std;

// void display(map<string, string>& buffer) {

//     for(auto kv : buffer) {
//         cout<<kv.first<<" "<<kv.second<<" ";
//     }
//     cout<<endl;
// }

// void test2() {

//     string key = "key";
//     string val = "val";
//     auto res = SSTable::convert_to_bytes(key, val);

// }

// void test1() {
//     map<string, string> buffer;
//     int i=0;
//     while(i < 5) {
//         buffer.insert({to_string(i), to_string(i)});
//         i++;
//     }
    
//     SSTable* sstable = new SSTable(buffer);
//     map<string, string> output_buffer = sstable->get_all_keys();
//     display(buffer);
//     display(output_buffer);
//     cout<<"Verifying both outputs"<<endl;
//     assert(output_buffer == buffer);
// }

