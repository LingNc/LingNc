#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
#define int long long
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0)
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl;
using namespace std;

const int N=1e2;
int a[N],n;
void solve(){
    cin>>n;
    memset(a,0,sizeof(a));
    int num,max_num=-1;
    bool res=0;
    foe(i,0,n-1){
        cin>>num;
        max_num=max(max_num,num);
        a[num]++;
    }
    foe(i,0,max_num){
        if(a[i]%2==1){
            res=true;
            break;
        }
    }
    if(res) yes;
    else no;
}
signed main(){
    IOS;
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}