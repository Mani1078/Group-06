#include <iostream>
#include <vector>
#include <string>
using namespace std;




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
    