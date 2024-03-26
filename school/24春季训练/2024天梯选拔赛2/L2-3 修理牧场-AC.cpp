#include<bits/stdc++.h>
#define ll long long
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,cost;
    cin>>n;
    priority_queue<int,vector<int>,greater<int>> q;
    foe(i,0,n-1){
        cin>>cost;
        q.push(cost);
    }
    int val=0,l=0;
    while(q.size()>1){
        l=0;
        l+=q.top();
        q.pop();
        l+=q.top();
        q.pop();
        q.push(l);
        val+=l;
    }
    cout<<val<<endl;
    return 0;
}