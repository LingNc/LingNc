#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<stack>
#include<cmath>
#include<queue>
#include<unordered_map>
#define ll long long
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'

using namespace std;
int n;

void solve(){
    int a[12];
    memset(a,0,sizeof a);
    cin>>n;
    int num;
    foe(i,1,n){
        cin>>num;
        if(num<=2048) a[(int)log2(num)]++;
    }
    foe(i,1,11){
        a[i]+=a[i-1]/2;
    }
    if(a[11]) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main(){
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}