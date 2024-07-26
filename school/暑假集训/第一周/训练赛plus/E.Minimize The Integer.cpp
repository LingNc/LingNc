#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<stack>
#include<cmath>
#include<queue>
#define ll long long
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#define fod(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'

using namespace std;

const int N=1e6+10;
int n,m;
void solve(){
    string res;
    queue<char> a,b;
    string in;
    cin>>in;
    for(auto i:in){
        if((i-'0')%2==0)
            a.push(i);
        else 
            b.push(i);
    }
    a.push('9'+1),b.push('9'+1);
    while(!a.empty()&&!b.empty()){
        if(a.front()<b.front()){
            res.push_back(a.front());
            a.pop();
        }
        else if(a.front()>b.front()){
            res.push_back(b.front());
            b.pop();
        }
        else if(a.front()=='9'+1&&b.front()=='9'+1) break;
    }
    cout<<res<<endl;
}
int main(){
    int T=1;
    cin>>T;
    getchar();
    while(T--) solve();
    return 0;
}