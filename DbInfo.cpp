// اینم مثل شماست ولی برای تیبل ها 
class DbInfo {
//کلاس دیبی‌اینفو آرایه‌ای از شِماهاست.هر شِما اطلاعات یدونه جدول بود به این صورت که اسم جدول و اطلاعات موجود تو هر ستون(اسم هر ستون و نوع داده موجود در هر ستون)رو میداد.حالا دیبی‌اینفو ارایه‌ای از همه جدول هاست
    

public:
    vector<Schema> tables;
    void addTable(Schema table) {
    tables.push_back(table);
}

    //یه لیست از اسم همه جدول هایی که داریم میده
    void showTables() {
        cout << "Tables in database:\n";
        for (const auto& table : tables) {
            cout << " ------- " << table.tableName << "\n";
        }
    }
//بررسی وجود یدونه جدول خاص براساس اسم اون جدول از بین همه جدول هایی که داریم
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