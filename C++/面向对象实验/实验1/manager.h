#include<iostream>
#include"include.h"
#define foe(i,a,b) for(int i=(a);i<=(b);i++)

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