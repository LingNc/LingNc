#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<vector>
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define string char
using namespace std;

bool is_gap(int year){
    return !(year%4)&&(year%100)||!(year%400);
}

typedef struct Student{
    string name[100],_time[100];
    int year,month,day;
    Student(string time[]){
        strcpy(_time,time);
        auto len=strlen(_time);
        int sign[2]={ 0 },si=0;
        foe(i,0,len-1){
            if(_time[i]=='-'){
                _time[i]=0;
                sign[si++]=i;
            }
        }
        year=stoi(time);
        month=stoi(time+sign[0]+1);
        day=stoi(time+sign[1]+1);
    }
    bool operator<(Student &b){
        return (year!=b.year)
            ?year<b.year
            :((month!=b.month)
                ?month<b.month
                :day<b.day);
    }
}Student;
void solve(){
    int n;
    cin>>n;
    Student min_stu("0000-0-0");

    foe(i,1,n){
        string name[100],time[100];
        cin>>name>>time;
        Student temp(time);
        stpcpy(temp.name,name);
        if(min_stu<temp) min_stu=temp;
    }
    cout<<min_stu.name<<endl;
}

int main(){
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}