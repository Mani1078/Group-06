#include <iostream>
#include <vector>
using namespace std;

// کامنت های اضافی پاک خواهند شد 


// نگهداری دیتا 
//برای هر رکورد 
struct MetaData {
    string tableName;
    bool isDeleted = false;
};


class Column {
public:
    string name;
    string type;

    Column(string name,string type) : name(name), type(type) {}      //سازنده ی ویژه 
    // مقدار دهی میتونه توی بدنه باشه 
};


// اطلاعات کالم ها و نمایششون 
class Schema {
public:
    string tableName;
    vector<Column> columns; // یعنی اشیای کلاس کالم که اسم و تایپ بودن رو میگیره 

    Schema(string name) : tableName(name) {}   // سازنده اصلی !!!!!     اسم تیبل رو میدی

    void addColumn(string name, string type) {   
        columns.emplace_back(name, type);      // از پوش بک هم میشد استفاده کرد  
        // تفاوتش با امپلیس بک اینه که این یکی درجا مقادیر رو در وکتور میسازه  (کپی نمیکنه)
    }

    void showColumns() {
        cout << "Columns of table " << tableName << ":\n";
        for (const auto &col : columns) {    // ببین این & جلوی کپی رو میگیره و رفرنس میده!!!!
                                             // یعنی این که اون کول یه ادرسه به مرجعش یعنی کالوم
            cout << "- " << col.name << "    ( " << col.type << " )\n";
        }
    }
    bool checkColumn(string columnName)  {
        for (const auto &col : columns) {
            if (col.name == columnName) {
                cout << "exists" ; 
                return true; 
            }
        }
        cout << "does not exist";
        return false;
      }
};

class Record {
public:
    MetaData metadata;
    vector<string> data;

    Record(string table, vector<string> values) {
        metadata.tableName = table;
        data = values;
    }
};

class DbInfo {
public:
    vector<string> tableNames;

    void addTable(string tableName) {
        tableNames.push_back(tableName);
    }

    void removeTable(string tableName) {
        for (size_t i = 0; i < tableNames.size(); i++) {   // سایز تی یجور اینتیجره ولی فقط اعداد طبیعی داره
            if (tableNames[i] == tableName) {
                tableNames.erase(tableNames.begin() + i); // موقعیت دقیق تیبل نیم 
                break;
            }
        }
    }

    void listTables() {
        cout << "Tables in database:\n";
        for (const auto &table : tableNames) {
            cout << "- " << table << "\n";
        }
    }
    bool checkTable(string tableName) {
        for (const auto &table : tableNames) {
            if (table == tableName) {
                cout << "table exists ! " ; 
                return true; 
            }
        }
        cout << " table does not exist" ; 
        return false;
}  };

