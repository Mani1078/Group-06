class Column {//این کلاسه میاد اطلاعات هر ستونمون رو میگه.مثلا میگه اسم ستونمون چیه و چه نوع داده‌ای توی این ستون هست
public:
    string name;
    string Type;

    Column(string colName, string colType) : name(colName), Type(colType) {} // نام ستون و نوعش رو در همین سانزده میگیریم 
};