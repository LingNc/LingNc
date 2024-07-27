#include<bits/stdc++.h>
using namespace std;

vector<int>v[300005];
bool q[300005];
bool pos[300005];
long long n,x,y,numx=0,numy=0;
void build(int a,int b)
{
    v[a].push_back(b);
    v[b].push_back(a);
}

void dfs1(int node)
{
    if(node==y)
    {
        return;
    }
    q[node]=1;
    int big=v[node].size();
    for(int i=0;i<big;i++)
    {
        if(!q[v[node][i]])
        {
            q[v[node][i]]=1;
            numx++;
            dfs1(v[node][i]);
        }
    }
}

void dfs2(int node)
{
    if(node==x)
    {
        return;
    }
    q[node]=1;
    int big=v[node].size();
    for(int i=0;i<big;i++)
    {
        if(!q[v[node][i]])
        {
            q[v[node][i]]=1;
            numy++;
            dfs2(v[node][i]);
        }
    }
}

int main()
{

    cin>>n>>x>>y;;
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        build(a,b);
    }
    dfs1(x);
    memset(q,0,sizeof(q));
    dfs2(y);
   cout<<n*(n-1)-(n-numx)*(n-numy)<<endl;
    return 0;
}