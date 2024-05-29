#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<queue>
#define ll long long
#define endl '\n'
#define foe(i,a,b) for(int i=a;i<=b;i++)
//priority_queue
using namespace std;
void priA(vector<int> &A){
    foe(i,0,A.size()-1){
        cout<<A[i]<<' ';
    }
    cout<<endl;
}

void solve(){
    ios::sync_with_stdio(0),cin.tie(0);
    int N;
    cin>>N;
    ll cha_max=-1;
    ll shouder,head;
    ll cha;
    ll sum=0;
    foe(i,1,N){
        cin>>shouder>>head;
        sum+=shouder;
        cha=head-shouder;
        if(cha>cha_max){
            cha_max=cha;
        }
    }
    cout<<sum+cha_max<<endl;
}
int main(){
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
