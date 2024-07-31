#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#define int long long
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'

using namespace std;
//记得1e5+10
const int N=5e2+10;
int n,m,dist[N],st[N];
int g[N][N];
//朴素版 稠密图 n很小的时候用 (n^2~m  1e2)
//n^2
int Dijkstra(){
    memset(dist,0x3f,sizeof(dist));
    dist[1]=0;
    //遍历所有点
    foe(i,1,n){
        //找到未确定的距离最小的点
        int t=-1;
        foe(j,1,n){
            if(!st[j]&&(t==-1 || dist[t]>dist[j]))
                t=j;
        }
        //确定这个路径最小
        st[t]=true;
        //if(t==n) break;
        // 判断从该点(t)出发的所有路径的点的距离最小值
        foe(j,1,n){
            if(g[t][j]!=0x3f3f3f3f3f3f3f3f)
                dist[j]=min(dist[j],dist[t]+g[t][j]);
        }
    }
    return (dist[n]==0x3f3f3f3f3f3f3f3f)?-1:dist[n];
}
signed main(){
    cin>>n>>m;
    memset(g,0x3f,sizeof(g));
    int x,y,c;
    foe(i,1,m){
        cin>>x>>y>>c;
        g[x][y]=min(g[x][y],c);
    }
    int t=Dijkstra();
    cout<<t<<endl;
    
    return 0;
}
/*
3 3
1 2 2
2 3 1
1 3 4

3
*/