#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Column;
class Record;
class Schema;
class DbInfo;

struct MetaData {
    string tableName;
    bool isDeleted;
};

class Column {
public:
    string name;
    string Type;

    Column(string colName, string colType) : name(colName), Type(colType) {} // نام ستون و نوعش رو در همین سانزده میگیریم 
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


// این کلاس برای اد کردن و نمایش و ... کالم هاست 
class Schema {
public:
    string tableName;
    vector<Column> columns;

    Schema(string name) : tableName(name) {}

    void addColumn(string colName, string colType) {
        columns.emplace_back(colName, colType);
    }

    void showColumns() {
        cout << tableName << ":\n";
        for (const auto &col : columns) { 
            cout << " -------> " << col.name << endl << col.Type << endl;
        }
    }
    bool checkColumn(string columnName) { 
       for (const auto &col : columns) {   // کانست برای امنیت کد هست ( متغیر تغییر نمیکنه) 
        if (col.name == columnName) { 
            cout << "exists" ;
                 return true; 
              } 
 } 
    cout << "does not exist"; 
       return false; 
  }
};


// اینم مثل شماست ولی برای تیبل ها 
class DbInfo {

    

public:
    vector<Schema> tables;
    void addTable(Schema table) {
    tables.push_back(table);
}

    
    void showTables() {
        cout << "Tables in database:\n";
        for (const auto& table : tables) {
            cout << " ------- " << table.tableName << "\n";
        }
    }

    bool chekTable(string tableName) {
        for (const auto &table :  tables) { 
            if (table.tableName == tableName) {
                return true;
            }
        }
        return false;
    }
   void removeTable(string tableName) { 
    for (auto it = tables.begin(); it != tables.end(); it++) { 
        if (it->tableName == tableName) { 
            tables.erase(it);  // میشد بجای اریس ( کامل پاک کردن ) بولین اون رو به دیلیتد تغییر بدیم 
            break; 
        } 
    } 
}
};

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

int main() {
    DataBase myDatabase;

    Schema users("Users");
    
    users.addColumn("ID", "int");
    users.addColumn("Name", "string");
   // myDatabase.addTable(users);
    myDatabase.dbInfo.addTable(users);
    myDatabase.insertRecord("Users", {"1", "Ali"});
    myDatabase.insertRecord("Users", {"2", "amir"});

    myDatabase.findRecords("Users","Ali");
    myDatabase.findRecords("Users",2);

    myDatabase.updateRecord("Users", 0, {"1", "Ali jadid "});

    myDatabase.findRecords("Users","Ali jadid ");


    myDatabase.deleteRecord("Users", 0);

    myDatabase.findRecords("Users","Ali jadid ");
    myDatabase.findRecords("Users","amir");

return 0;
}