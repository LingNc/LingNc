#include<iostream>
#include<algorithm>
#define ll long long
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'

using namespace std;

const int N=10;

int n;
int path[N];
bool st[N];

void dfs(int f){
    if(f==n){
        foe(i,0,n-1)
            cout<<path[i]<<' ';
            cout<<endl;
        return ;
    }
    foe(i,1,n){
        if(!st[i]){
            path[f]=i;
            st[i]=true;
            dfs(f+1);
            st[i]=false;
        }
    }

}
int main(){
    cin>>n;

    dfs(0);
    return 0;
}