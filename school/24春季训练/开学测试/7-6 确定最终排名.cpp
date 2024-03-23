#include<iostream>
#include<algorithm>
#define ll long long
#define endl '\n'
#define foe(i,a,b) for(ll i=a;i<=b;i++)
#define foee(i,a1,b1,j,a2,b2) foe(i,a1,b1)foe(j,a2,b2)
using namespace std;

typedef struct{
    char s[101];
    int solve;
}Team;
bool cmp(Team a,Team b){
    return a.solve>b.solve;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        Team list[n];
        foe(i,0,n-1){
            cin>>list[i].s>>list[i].solve;
        }
        sort(list,list+n,cmp);
        foe(i,0,n-1){
            cout<<i+1<<' '<<list[i].s<<' '<<list[i].solve<<endl;
        }
    }
    return 0;
}