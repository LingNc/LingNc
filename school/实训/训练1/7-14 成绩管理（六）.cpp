#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<vector>
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define string char
using namespace std;

typedef struct Student{
    string name[100];
    int a,b,c;
}Student;

void print(Student &stu){
    cout<<stu.name<<' '<<stu.a<<' '<<stu.b<<' '<<stu.c<<endl;
}
void solve(){
    int n;
    cin>>n;
    Student stu[n];
    string name[100];
    int a,b,c;
    int a_max=-1,b_max=-1,c_max=-1;
    foe(i,0,n-1){
        cin>>name>>a>>b>>c;
        strcpy(stu[i].name,name);
        stu[i].a=a;
        stu[i].b=b;
        stu[i].c=c;
        a_max=max(a,a_max);
        b_max=max(b,b_max);
        c_max=max(c,c_max);
    }
    for(auto &it:stu){
        if(it.a==a_max) print(it);
    }
    for(auto &it:stu){
        if(it.b==b_max) print(it);
    }
    for(auto &it:stu){
        if(it.c==c_max) print(it);
    }
}

int main(){
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}