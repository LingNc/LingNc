#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define ll long long
#define endl '\n'
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define foee(i,a1,b1,j,a2,b2) foe(i,a1,b1)foe(j,a2,b2)
using namespace std;

int main(){
    char pot[15]="chi1 huo3 guo1";
    int num=0,i=1,first=0;
    while(1){
        char m[81]={0};
        scanf("%[^\n]%*c",m);
        if(m[0]=='.'&&m[1]==0) break;
        if(strstr(m,pot)!=NULL){
            if(first==0)
                first=i;
            num++;
        }
        i++;
    }
    if(first==0) cout<<i-1<<endl<<"-_-#";
    else cout<<i-1<<endl<<first<<' '<<num;
    return 0;
}