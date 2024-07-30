#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0)

using namespace std;
using i32=signed;
const int N=10;

typedef pair<int,char> PII;
void solve(){
    int n;
    cin>>n;
    char ch;
    queue<PII> q;
    int sum=0;
    foe(i,1,n){
        cin>>ch;
        if(!q.empty()&&(ch==')'||ch=='_')){
            auto t=q.front();
            sum+=i-t.first;
            q.pop();
        }
        else q.push({ i,ch });
    }
    cout<<sum<<endl;
}
i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}