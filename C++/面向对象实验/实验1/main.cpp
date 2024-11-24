#include"include.h"
#include<iostream>
using namespace std;
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
    cout<<"当前Student对象个数："<<Student::count(); //调用Student的静态函数输出静态私有变量
    Manager manager;
    cout<<manager.scoresAvg(*ppSS[1]); //计算输出第2个学生的平均成绩
    Print print;
    print.printStudent(*ppSS[2]);                      //输出第3个学生的信息
    delete ppSS[studentCount-1];                       //删除1个学生对象
    cout<<"当前Student对象个数："<<Student::count(); //调用Student的静态函数输出静态私有变量

    //删除使用new动态创建的对象
    for(int i=0; i<studentCount-1; i++)
        delete ppSS[i];
    //删除使用new动态创建的数组
    delete[] ppSS;
    return 0;
}