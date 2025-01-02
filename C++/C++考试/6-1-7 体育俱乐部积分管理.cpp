#include <iostream>
using namespace std;
class Ball{
protected:
    string opponent; // 对手
public:
    virtual void display()=0;//显示比赛积分
};

class Basketball:public Ball{
    int score;
public:
    Basketball(string opp,int num,int num2){
        opponent=opp;
        if(num>num2) score=2;
        else if(num<num2) score=1;
    }
    void display(){
        cout<<opponent<<' '<<score<<endl;
    }
};

class Football: public Ball{
    int score;
public:
    Football(string opp,int num,int num2){
        opponent=opp;
        if(num>num2) score=3;
        else if(num==num2) score=1;
        else score=0;
    }
    void display(){
        cout<<opponent<<' '<<score<<endl;
    }
};

class Volleyball: public Ball{
    int score;
public:
    Volleyball(string opp,int num,int num2){
        opponent=opp;
        if(num==3&&num2==0) score=3;
        else if(num==3&&num2==1) score=3;
        else if(num==3&&num2==2) score=2;
        else if(num==2&&num2==3) score=1;
        else score=0;
    }
    void display(){
        cout<<opponent<<' '<<score<<endl;
    }
};

int main(){
    Ball *pb[20];
    int type,num,num2,i=0;
    string duishou;
    char ch;
    while(cin>>type,type!=0){
        cin>>duishou>>num>>ch>>num2;
        if(type==1){
            pb[i]=new Basketball(duishou,num,num2);
        }
        else if(type==2){
            pb[i]=new Football(duishou,num,num2);
        }
        else if(type==3){
            pb[i]=new Volleyball(duishou,num,num2);
        }
        i++;
    }
    for(int j=0; j<i; j++){
        pb[j]->display();
    }
    return 0;
}