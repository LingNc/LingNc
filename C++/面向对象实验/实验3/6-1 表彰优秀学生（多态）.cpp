#include<iostream>
#include <string>
using namespace std;

class Student{
protected:
    string num;
    string name;
    int score1;
    int score2;
    static double price_avg_score;
public:
    Student(string num, string name, int score1, int score2) : num(num), name(name), score1(score1), score2(score2) {}
    virtual void display()=0;
};

class GroupA:public Student{
public:
    GroupA(string num,string name,int score1,int score2):Student(num,name,score1,score2){
        price_avg_score=max(price_avg_score,(score1+score2)/2.0);
    }
    virtual void display(){
        if((score1+score2)/2.0>=price_avg_score)
            cout<<num<<" "<<name<<endl;
    }
};

class GroupB:public Student{
    char grade;
public:
    GroupB(string num,string name,int score1,int score2,char grade):Student(num,name,score1,score2),grade(grade){
        price_avg_score=max(price_avg_score,(score1+score2)/2.0);
    }
    virtual void display(){
        if((score1+score2)/2.0>=price_avg_score*0.7&&grade=='A'||(score1+score2)/2.0>=price_avg_score)
            cout<<num<<" "<<name<<endl;
    }
};

class GroupC:public Student{
    int score3;
    int score4;
    int score5;
public:
    GroupC(string num,string name,int score1,int score2,int score3,int score4,int score5):Student(num,name,score1,score2),score3(score3),score4(score4),score5(score5){}
    virtual void display(){
        if((score1+score2+score3+score4+score5)/5.0>=price_avg_score*0.9)
            cout<<num<<" "<<name<<endl;
    }
};

double Student::price_avg_score=0;
int main(){
    const int Size=50;
    string num,name;
    int i,ty,s1,s2,s3,s4,s5;
    char gs;
    Student *pS[Size];
    int count=0;
    for(i=0;i<Size;i++){
        cin>>ty;
        if(ty==0) break;
        cin>>num>>name>>s1>>s2;
        switch(ty){
        case 1:pS[count++]=new GroupA(num,name,s1,s2); break;
        case 2:cin>>gs; pS[count++]=new GroupB(num,name,s1,s2,gs); break;
        case 3:cin>>s3>>s4>>s5; pS[count++]=new GroupC(num,name,s1,s2,s3,s4,s5); break;
        }
    }
    for(i=0;i<count;i++){
        pS[i]->display();
        delete pS[i];
    }
    return 0;
}
