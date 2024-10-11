#include<bits/stdc++.h>
#define ll long long
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'

using namespace std;

const int N=3;


int bfs(string start,string end){
    unordered_map<string,int> d;
    queue<string> q;
    q.push(start);
    d[start]=0;

    int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
    while(q.size()){
        auto t=q.front();
        q.pop();

        int k=t.find('.');
        int x=k/3,y=k%3;

        int dis=d[t];
        if(t==end)
            return dis;
        foe(i,0,3){
            int a=x+dx[i],b=y+dy[i];
            if(a>=0&&a<N&&b>=0&&b<N){
                swap(t[k],t[3*a+b]);
                if(d.count(t)==0){
                    d[t]=dis+1;
                    q.push(t);
                }
                swap(t[k],t[3*a+b]);
            }
        }
    }
    return -1;
}

int main(){
    string start;
    string end;
    cin>>start>>end;
    cout<<bfs(start,end)<<endl;
    return 0;
}