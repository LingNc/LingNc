#include <bits/stdc++.h>
#define ll long long
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'
using namespace std;

bool issqrt(int x);

void solve(){
    while(1){
        int A,B;
        cin>>A>>B;
        if(A==0&&B==0) break;
        int num=0;
        foe(i,A,B){
            num+=(issqrt(i))?1:0;
        }
        cout<<num<<endl;
    }
}

bool issqrt(int x){
    int sq=sqrt(x);
    if(sq*sq==x)
        return true;
    else
        return false;
}

int main(){
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
