#include <iostream>
#include <vector>
#include <string>
using namespace std;



struct MetaData {
    string tableName;
    bool isDeleted;
};


class Record {
public:
    MetaData metaData;
    vector<string> data;

    Record(string tableName, vector<string> recordData) {
        metaData.tableName = tableName;
        metaData.isDeleted = false; //یعنی وجود داره دیگه 
        data = recordData;
    }
};

