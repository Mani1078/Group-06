// این کلاس برای اد کردن و نمایش و ... کالم هاست 
class Schema {
public://کلاس شِما میاد اطلاعات یدووونه جدولو میگه.مثلا میگه جدولمون اسمش چیه و اطلاعات جدولمون رو با صورت ستونی مشخص میکنه که اسم ستوناش چیه و چه نوع داده ای توی هر ستونش هست
    string tableName;
    vector<Column> columns;

    Schema(string name) : tableName(name) {}
// با کانستراکتور اومدیم اسم جدولمون رو گرفتیم
    void addColumn(string colName, string colType) {//برای اضافه کردن یه ستون جدید به جدولمون
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