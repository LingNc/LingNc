#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#define ll long long
#define endl '\n'
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define foee(i,a1,b1,j,a2,b2) foe(i,a1,b1)foe(j,a2,b2)
using namespace std;

typedef struct stu{
    int grede;
    string email;
}ST;
bool cmp(ST a,ST b){
    if(a.grede!=b.grede)
        return a.grede>b.grede;
    else
        return strcmp(a.email.c_str(),b.email.c_str())<=0;
}
int main(){
    int N,G,K;
    cin>>N>>G>>K;
    ST student[10];
    foe(i,0,N-1){
        cin>>student[i].email>>student[i].grede;
    }
    sort(student,student+N,cmp);
    int num=0;
    foe(i,1,K){
        cout<<i<<' '<<student[num].email<<' '<<student[num].grede<<endl;
        if(num+1<=N-1){
            if(student[num+1].grede==student[num].grede)
                i--;
            else{
                i=num+1;
            }
        }
        num++;
    }
    return 0;
}