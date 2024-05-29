#include<iostream>
#include<algorithm>
#define ll long long
#define endl '\n'
#define foe(i,a,b) for(int i=a;i<=b;i++)

using namespace std;

void solve(){
    ios::sync_with_stdio(0),cin.tie(0);
    int N,num,max=-1;
    cin>>N;
    int first;
    foe(i,1,N){
        cin>>num;
        if(i==1) first=num;
        if(num>first){
            max=i;
            break;
        }
    }
    cout<<max<<endl;
}

int main(){
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
