#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n,m,s,k;
char t;
queue<char>q[N];
stack<char>v;;
int main(){
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            cin>>t;
            q[i].push(t);
        }
    }
    int k;
    while(cin>>k&&k!=-1){
        if(k==0&&v.size()!=0){
            cout<<v.top();
            v.pop();
        }
        else if(k!=0){
            if(q[k].size()==0) continue;
            else{
                if(v.size()==s){
                    cout<<v.top();
                    v.pop();
                }
                v.push(q[k].front());
                q[k].pop();
            }
        }
    }
    return 0;
}