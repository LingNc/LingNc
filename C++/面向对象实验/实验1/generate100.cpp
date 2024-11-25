#include<cstring>
#include<iostream>
#include<vector>
#include<random>
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
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
    Student(const Student &stu);
    //析构函数
    ~Student();
    static int count();
    // 撰写输出本对象信息函数
    void info();
    // 友元类和友元函数声明
    // friend class Manager;
    // friend void Print::printStudent(Student &s);
};
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
Student::Student(const Student &stu)
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
    std::cout<<sNo<<' '<<sName<<' '<<(sClass?sClass:"Null")<<' ';
    for(auto &it:scores) std::cout<<it<<' ';
    std::cout<<std::endl;
}

void dtoa(int num,char *name){
    string res="";
    while(num){
        res+='a'+num%26;
        num/=26;
    }
    foe(i,0,res.size()-1)
        name[i]=res[i];
    name[res.size()]='\0';
}
int Student::_count=0;
int main(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1,100);
    vector<Student> stu;
    foe(i,1,100){
        int a[3]={ 0 };
        foe(i,0,2) a[i]=distrib(gen);
        char name[20];
        dtoa(distrib(gen),name);
        char *pClass=new char[20];
        strcpy(pClass,"班级");
        dtoa(distrib(gen),pClass+6);
        auto it=new Student(i,name,pClass,a);
        stu.push_back(*it);
        delete it;
    }
    foe(i,0,99){
        stu[i].info();
    }
    return 0;
}