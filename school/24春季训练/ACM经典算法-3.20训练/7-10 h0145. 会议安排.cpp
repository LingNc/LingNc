#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
#define ll long long
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'

using namespace std;
typedef struct{
    int start,end;
}Tm;
void solve();
int main(){
    int m;
    cin>>m;
    while(m--){
        solve();
    }
    return 0;
}
bool cmp(Tm *a,Tm *b){
    return a->end-b->end;
}
void solve(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    Tm time[n];
    foe(i,0,n)
        cin>>time[i].start>>time[i].end;
    sort(time,time+n,cmp);
    int num=1;
    foe(i,1,n-1){
        
    }
}
