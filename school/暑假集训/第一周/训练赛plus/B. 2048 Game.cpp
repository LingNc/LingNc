#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<stack>
#include<cmath>
#include<queue>
#include<unordered_map>
#define ll long long
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'

using namespace std;

const int N=1e1+10;
int n;

void solve(){
    cin>>n;
    int s;
    priority_queue<int,vector<int>,less<int>> qq;
    foe(i,0,n-1){
        cin>>s;
        qq.push((int)log2(s));
    }
    bool res=0;
    int t=qq.top();
    qq.pop();
    if(t==11) res=true; 
    while(qq.empty()!=1){
        int t2=qq.top();
        qq.pop();
        if(t2==11||t==11){
            res=true;
            break;
        }
        if(t==t2){
            qq.push(t+1);
            t=qq.top();
            qq.pop();
            if(t==11){
                res=true;
                break;
            }
        }
        else t=t2;
    }
    if(res) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main(){
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}