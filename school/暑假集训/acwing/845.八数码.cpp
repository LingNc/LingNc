#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<unordered_map>
#define ll long long 
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'

using namespace std;

const int N=3;


int bfs(string start){
    unordered_map<string,int> d;
    queue<string> q;
    q.push(start);
    d[start]=0;

    int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
    string end="12345678x";
    while(q.size()){
        auto t=q.front();
        q.pop();

        int k=t.find('x');
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
    char ch;
    foe(i,0,8){
        cin>>ch;
        start+=ch;
    }
    cout<<bfs(start)<<endl;
    return 0;
}