#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#define ll long long
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'

using namespace std;
void solve();
int main(){
    ios::sync_with_stdio(0);
    //int T;cin>>T;while(T--)
        solve();
    
}
void solve(){
    int N;
    cin>>N;
    vector<int> s(N,0);
    foe(i,0,N-1){
        cin>>s[i];
    }
    int k=0,l=1,max=1;
    foe(i,0,N-2){
        if(s[i+1]>s[i]){
            l++;
            if(l>max){
                max=l;
                k=i+1;
            }
        }
        else{
            l=1;
        }

    }
    foe(i,k-max+1,k){
        cout<<s[i];
        if(i!=k) cout<<' ';
    }
}