#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


//
struct MetaData { 
    string tableName; 
    bool isDeleted = false; 
};


//cloumn 
class Column {
    public:
        string name;
        string type;
    
        Column(string name, string type) : name(name), type(type) {}
    };
    

//رکورد 
// وکتور آزاده !!!! 
class Record {
public:
    MetaData metadata;
    vector<string> data;

    Record(string table, vector<string> values) {
        metadata.tableName = table;
        data = values;
    }
};
