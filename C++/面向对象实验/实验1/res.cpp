#include<iostream>
#include<cstring>
#include<vector>
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;

// class Print;
class Student;

class Print{
public:
    void printStudent(Student &s);
};

class Manager;

class Student{
private:
    int sNo; // 学号
    char sName[20]; // 姓名
    char *sClass; // 班级
    int scores[3]; // 成绩
    static int _count;
public:
    // 撰写3个构造函数：带参、不带参的和拷贝构造函数
    Student();
    Student(int sNo,char Name[20],char *Class,int scores[3]);
    Student(Student &stu);
    //析构函数
    ~Student();
    static int count();
    // 撰写输出本对象信息函数
    void info();
    // 友元类和友元函数声明
    friend class Manager;
    friend void Print::printStudent(Student &s);
};

//管理者类
class Manager{
    int mNo;
    //管理者编号
    char mName[20]; //管理者姓名
public:
    int scoresAvg(Student &s);
};
struct studentInfo{
    int sNo;        // 学号
    char sName[20]; // 姓名
    char *sClass;   // 班级
    int scores[3];  // 成绩
};

void Print::printStudent(Student &s){
    s.info();
}

// 撰写3个构造函数：带参、不带参的和拷贝构造函数
Student::Student(){
    _count++;
}
Student::Student(int sNo,char Name[20],char *Class,int cores[3])
    :sNo(sNo),sClass(Class){
    strcpy(sName,Name);
    foe(i,0,2) scores[i]=cores[i];
    _count++;
}
Student::Student(Student &stu)
    :sNo(stu.sNo),sClass(stu.sClass){
    strcpy(sName,stu.sName);
    foe(i,0,2) scores[i]=stu.scores[i];
    _count++;
}
//析构函数
Student::~Student(){
    _count--;
}
int Student::count(){
    return _count;
}
// 撰写输出本对象信息函数
void Student::info(){
    std::cout<<sNo<<' '<<sName<<' '<<(sClass?sClass:"Null")<<' '<<sNo<<' ';
    for(auto &it:scores) std::cout<<it<<' ';
    std::cout<<std::endl;
}

int Manager::scoresAvg(Student &s){
    int sum=0;
    foe(i,0,2){
        sum+=s.scores[i];
    }
    return sum/3;
}
int Student::_count=0;
int main(){
    //有5个学生的信息
    struct studentInfo stuInfo[5]={
        { 0001,"张三","计算机23-1",{ 68,89,79 } },
        { 0002,"李四","计算机23-2",{ 80,85,92 } },
        { 0001,"王五","计算机23-1",{ 95,90,93 } },
        { 0001,"赵六","计算机23-2",{ 87,93,86 } },
        { 0001,"郑七","计算机23-1",{ 97,84,74 } },
    };
    //计算结构包含的学生信息个数
    int studentCount=sizeof(stuInfo)/sizeof(struct studentInfo);
    //动态创建学生对象指针数组
    Student **ppSS=new Student*[studentCount];
    //动态创建每个学生对象
    for(int i=0; i<studentCount; i++)
        ppSS[i]=new Student(stuInfo[i].sNo,stuInfo[i].sName,stuInfo[i].sClass,stuInfo[i].scores);
    cout<<"当前Student对象个数："<<Student::count()<<' '<<endl; //调用Student的静态函数输出静态私有变量
    Manager manager;
    cout<<"第2个学生的平均成绩: "<<manager.scoresAvg(*ppSS[1])<<' '<<endl; //计算输出第2个学生的平均成绩
    Print print;
    cout<<"第3个学生的信息:";
    print.printStudent(*ppSS[2]);                      //输出第3个学生的信息
    delete ppSS[studentCount-1];
    studentCount--;
    //删除1个学生对象
    cout<<"当前Student对象个数："<<Student::count()<<endl; //调用Student的静态函数输出静态私有变量
    // 剩下所有学生的信息
    cout<<"剩下所有学生的信息："<<endl;
    foe(i,0,studentCount-1)
        print.printStudent(*ppSS[i]);

    //删除使用new动态创建的对象
    for(int i=0; i<studentCount-1; i++)
        delete ppSS[i];
    //删除使用new动态创建的数组
    delete[] ppSS;
    cout<<endl;
    return 0;
}
