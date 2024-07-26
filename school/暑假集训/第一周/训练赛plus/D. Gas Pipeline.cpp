#include<bits/stdc++.h>
#define int long long
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0)
using namespace std;

string road;
int n;
double a,b;
void solve(){
    cin>>n>>a>>b;
    cin>>road;
    int r=n-1,l=0;
    int cost=0;
    while(r-->0)
        if(road[r]=='1') break;
    while(l++<n-1)
        if(road[l]=='1') break;
    cost=(l+1)*(a+b)+(r+1)*(a+b);
    if(l==n&&r==-1){
        cost=n*a+(n+1)*b;
        cout<<cost<<endl;
        return;
    }
    //最少下降的管道数
    int min_0=floor(2*a/b);
    int have_1=0;
    foe(i,l,r-1){
        if(road[i]=='1'&&road[i+1]=='1'){
            have_1++;
        }
    }
    int have_0=r-l-1-have_1;
    int cheap=0;
    if(have_0>=min_0){
        cheap=2*a-have_0*b;
    }
    cost+=(r-l)*a+(r-l+1)*b*2+cheap;
    cout<<cost<<endl;

}

signed main(){
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}