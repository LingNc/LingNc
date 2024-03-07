#include<iostream>
#include<algorithm>
#define ll long long
#define endl '\n'
#define foe(i,a,b) for(ll i=a;i<=b;i++)
#define foee(i,a1,b1,j,a2,b2) foe(i,a1,b1)foe(j,a2,b2)
using namespace std;
void prin(int n,char ch);
int main(){
    int n;
    cin>>n;
    if(n<=0||n>=10){
        puts("输入数据有误！");
        return 0;
    }
    for(int i=1;i<=n;i++){
        prin(n-i,' ');
        prin(2*i-1,'*');
        if(i<=n-1) putchar(endl);
    }
    return 0;
}
void prin(int n,char ch){
    for(int i=1;i<=n;i++){
        putchar(ch);
    }
}