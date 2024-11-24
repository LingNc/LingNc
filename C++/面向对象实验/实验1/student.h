#include<cstring>
#include<iostream>
#include"include.h"
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
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
#undef foe(i,a,b)