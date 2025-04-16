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