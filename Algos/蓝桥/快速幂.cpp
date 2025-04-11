#include <bits/stdc++.h>
using namespace std;
using i64=long long;
const int mod=1e9+7;

i64 pow(i64 a,i64 b){
    i64 res=1%mod,t=a;
    while(b){
        if(b&1) res=res*t%mod;
        t=t*t%mod;
        b>>=1;
    }
    return res;
}