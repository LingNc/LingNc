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

typedef struct Student{
    string name[100];
    double sc1,sc2;
}Student;

const bool cmp(const Student &a,const Student &b){
    if(a.sc1!=b.sc1){
        return a.sc1>b.sc1;
    }
    else if(a.sc2!=b.sc2){
        return a.sc2>b.sc2;
    }
    else{
        return strcmp(a.name,b.name)<=0;
    }
}
void solve(){
    int n;
    cin>>n;
    Student stu[n];
    foe(i,0,n-1){
        auto &name=stu[i].name;
        auto &a=stu[i].sc1;
        auto &b=stu[i].sc2;
        cin>>name>>a>>b;
    }
    sort(stu,stu+n,cmp);
    int st_k=1;
    auto &it=stu[0];
    printf("%d %s %.2lf %.2lf\n",1,it.name,it.sc1,it.sc2);
    foe(i,1,n-1){
        auto &it=stu[i];
        if(it.sc1==stu[i-1].sc1&&it.sc2==stu[i-1].sc2){
            printf("%d %s %.2lf %.2lf\n",st_k,it.name,it.sc1,it.sc2);
            continue;
        }
        else{
            st_k=i+1;
            printf("%d %s %.2lf %.2lf\n",i+1,it.name,it.sc1,it.sc2);
        }
    }
    Student a;
}

int main(){
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}