#include<cstring>
#include<iostream>
#include"student.h"
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
// 撰写3个构造函数：带参、不带参的和拷贝构造函数
Student::Student(){}
Student::Student(int sNo,char Name[20],char *Class,int scores[3]):sNo(sNo),sClass(Class){
    strcpy(sName,Name);
    scores=scores;
}
Student::Student(Student &stu):sNo(stu.sNo),sClass(stu.sClass){
    strcpy(sName,stu.sName);
    foe(i,0,2) scores[i]=stu.scores[i];
}
//析构函数
Student::~Student(){
    delete[] sName;
    delete[] scores;
}
int Student::count(){
    return _count;
}
// 撰写输出本对象信息函数
void Student::info(){
    std::cout<<sName<<' '<<(sClass?sClass:"Null")<<' '<<sNo<<' ';
    for(auto &it:scores) std::cout<<it<<' ';
    std::cout<<std::endl;
}
#undef foe(i,a,b)