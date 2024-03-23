#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>
#define ll long long
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'

using namespace std;
typedef struct{
    int val,times;
}point;
void boom(vector<vector<point>> &map,int x1,int y1,int x2,int y2,int times);
int main(){
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    vector<vector<point>> map(n+1,vector<point>(m+1,{0,0}));
    int x1,y1,x2,y2;
    foe(i,1,x){
        cin>>x1>>y1>>x2>>y2;
        boom(map,x1,y1,x2,y2,i);
    }
    int a,b,loc;
    foe(i,1,y){
        cin>>a>>b;
        loc=map[a][b].val;
        if(loc){
            cout<<"Y "<<loc<<' '<<map[a][b].times<<endl;
        }
        else{
            cout<<'N'<<endl;
        }
    }
    return 0;
}
void boom(vector<vector<point>> &map,int x1,int y1,int x2,int y2,int times){
    foe(i,x1,x2)foe(j,y1,y2){
        map[i][j].val++;
        map[i][j].times=times;
    }
}