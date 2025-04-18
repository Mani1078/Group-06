#include <iostream>
#include <vector>
#include <string>
using namespace std;






class DataBase {
private:
    vector<Record> records;

public:

    DbInfo dbInfo;
  




    void insertRecord(string tableName, vector<string> recordData) {
        if (dbInfo.chekTable(tableName)) {
            records.emplace_back(tableName, recordData);
            cout << "Record added to " << tableName << "!\n";
        } else {
            cout << " doesn't  exist!\n";
        }
    }



    void findRecords(string table_name,string find) {
        int index=0;
        vector<int> str_fields;
        for (auto& table:dbInfo.tables ){//گرفتن اندیس ستونهایی که در table رشته هستند
            if(table.tableName==table_name){
                for (auto& col: table.columns){
                    if( col.Type=="string"){
                        str_fields.push_back(index);
                    }
                index++;
                }
            }    
        }
        for (const auto& record : records) {
            if (record.metaData.tableName == table_name && !record.metaData.isDeleted) {
                for(int i:str_fields){
                    if (record.data[i]==find){
                        for (const auto& field : record.data) {
                            cout << " - " << field << "\n";
                        }
                    }
                }
            }
        }
    }
    void findRecords(string table_name,int find) {
        int index=0;
        vector<int> str_fields;
        for (auto& table:dbInfo.tables ){//گرفتن اندیس ستونهایی که در table رشته هستند
            if(table.tableName==table_name){
                for (auto& col: table.columns){
                    if( col.Type=="int"){
                        str_fields.push_back(index);
                    }
                index++;
                }
            }    
        }
        for (const auto& record : records) {
            if (record.metaData.tableName == table_name && !record.metaData.isDeleted) {
                for(int i:str_fields){
                    if (record.data[i]==to_string(find)){
                        for (const auto& field : record.data) {
                            cout << " - " << field << "\n";
                        }
                    }
                }
            }
        }
    }
    void findRecords(string table_name,float find) {
        int index=0;
        vector<int> str_fields;
        for (auto& table:dbInfo.tables ){//گرفتن اندیس ستونهایی که در table رشته هستند
            if(table.tableName==table_name){
                for (auto& col: table.columns){
                    if( col.Type=="float"){
                        str_fields.push_back(index);
                    }
                index++;
                }
            }    
        }
        for (const auto& record : records) {
            if (record.metaData.tableName == table_name && !record.metaData.isDeleted) {
                for(int i:str_fields){
                    if (record.data[i]==to_string(find)){
                        for (const auto& field : record.data) {
                            cout << " - " << field << "\n";
                        }
                    }
                }
            }
        }
    }
    

    void updateRecord(string tableName, int recordIndex, vector<string> newData) {
        for (auto& record : records) {
            if (record.metaData.tableName == tableName && !record.metaData.isDeleted && recordIndex == 0) {
                record.data = newData;
                cout << "Record updated in " << tableName << "!\n";
                return;
            }
            recordIndex--;
        }
        cout << "Record not found!\n";
    }

    void deleteRecord(string tableName, int recordIndex) {
        for (auto &record : records) {
            if (record.metaData.tableName == tableName && !record.metaData.isDeleted && recordIndex == 0) {
                record.metaData.isDeleted = true;
                cout << "Record deleted from " << tableName << "!\n";
                return;
            }
            recordIndex--;
        }
        cout << "Record not found!\n";
    }
};