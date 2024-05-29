#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
#define ll long long
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'

using namespace std;
void solve();
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    //int T;cin>>T;while(T--)
        solve();
    
}
void solve(){
    int T;
    cin>>T;
    int v1=9,v2=3;
    int x1=0,x2=0,flag=1,sleep=0,k=0;
    for(int i=1;i<=T;i++){
        if(flag) k++;
        if(flag==0) sleep++;
        
        if(k==10){
            if(x1>x2){
                flag=0;
            }
            else{
                flag=1;
            }
            k=0;
        }
        if(sleep==30){
            flag=1;
            sleep=0;
        }

        x2+=v2;
        if(flag) x1+=v1;
    }
    if(x1>x2) cout<<"^_^ "<<x1;
    else if(x1<x2) cout<<"@_@ "<<x2;
    else cout<<"-_- "<<x1;
}