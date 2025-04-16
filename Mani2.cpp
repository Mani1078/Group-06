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
    
    
        // چون ابعاد کد کوچیک هست 
        //کل رکورد های یک تیبل رو نمایش میدیم 
        // برای فایند دونه دونه رکورد ها //
        // میایم یک تابع دیگر برای فایند کردن جزیی تر تعریف میکنیم و داخلش  ... 
        //اجزای وکتور های داخل تیبل رو چک میکنیم 
        vector<Record> findRecords(string tableName) {
            vector<Record> result;
            for (const auto& record : records) {
                if (record.metaData.tableName == tableName && !record.metaData.isDeleted) {
                    result.push_back(record);
        
                    for (const auto& field : record.data) {
                        cout << " - " << field << "\n";
                    }
                }
            }
            if (result.empty()) {
                cout << "No records found for table: " << tableName << "\n";
            }
        
            return result;
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
    