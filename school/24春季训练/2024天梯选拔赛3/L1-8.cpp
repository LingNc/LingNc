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
    string res;
    int N;
    cin>>N;
    vector<int> s(N,0);
    foe(i,0,N-1){
        cin>>s[i];
    }
    vector<int> sub(N,0),m(N,0);
    int max=-1;
    foe(i,0,N-1){
        int num=s[i];
        sub.push_back(num);
        for(int j=i+1;i<=N-1;i++){
            if(s[j]>num){
                sub.push_back(num);
                num=s[j];
            }
        }
        if(sub.size()>max){
            max=sub.size();
            m.swap(sub);
        }
        sub.clear();
    }
    foe(i,0,m.size()-1){
        cout<<m[i]<<' ';
    }
}