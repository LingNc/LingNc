#include<bits/stdc++.h>
#define int long long 
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0)
#define all(a) a.begin(),a.end()
using i32=signed;
using namespace std;


// int have_one(int num){
//     int res=0;
//     while(num){
//         res+=num&1;
//         num>>=1;
//     }
//     return res;
// }
i32 times(i32 num){
    int t=0,res=0;
    while(num){
        t++;
        if(num&1) res+=(i32)pow(2,t)-1;
        num>>=1;
    }
    return res;
}
void solve(){
    int x,y;
    cin>>x>>y;
    cout<<times(y+x)-times(x)<<endl;
}

i32 main(){
    IOS;
    i32 T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}
/*
001110 0
001111 1 1 1
010000 2 4 5
010001 3 1 6
010010 4 2 8
010011 5 1 9

000001 1 2^1-1
000010 3 2^2-1
000100 7 2^3-1
001000 15 2^4-1
010000 31 2^5-1
*/
// 101110