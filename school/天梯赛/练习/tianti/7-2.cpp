#include<bits/stdc++.h>
#define foe(i,a,b) for(int i=(a);i<(b);++i)
#define fod(i,a,b) for(int i=(a);i>(b);--i)
// #define endl '\n'
using namespace std;
using i32=int;
using i64=long long;
#define int long long

void print_space(int num){
    foe(i,0,num) cout<<' '<<' ';
}

void print_up(char start,int num){
    foe(i,0,num){
        cout<<(char)(start+i)<<' ';
    }
}
void print_down(char start,int num){
    foe(i,0,num){
        cout<<(char)(start-i)<<' ';
    }
}

void solve(){
    int n;
    cin>>n;
    foe(i,1,n/2+2){
        print_space(n/2-i+1);
        print_up('A',i);
        print_down('A'+i-2,i-1);
        cout<<endl;
    }
    foe(i,0,n/2){
        print_space(i+1);
        print_up('A',n/2-i);
        print_down('A'+n/2-i-2,n/2-i-1);
        cout<<endl;
    }
}

i32 main(){
    i32 T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}