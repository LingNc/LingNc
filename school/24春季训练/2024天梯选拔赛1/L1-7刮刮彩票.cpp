#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#define ll long long
#define endl '\n'
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define foee(i,a1,b1,j,a2,b2) foe(i,a1,b1)foe(j,a2,b2)
using namespace std;

int main(){
    int prise[]={ 10000,36,720,360,80,252,108,72,54,180,72,180,119,36,306,1080,144,1800,3600 };
    vector<vector<int>> map(4,vector<int>(4,0));
    int num[10]={ 0 },x0,y0;
    foe(i,1,3)foe(j,1,3){
        cin>>map[i][j];
        num[map[i][j]]=1;
        if(map[i][j]==0){
            x0=i,y0=j;
        }
    }
    foe(i,1,9){
        if(num[i]==0){
            map[x0][y0]=i;
        }
    }
    int x,y,sum=0;
    foe(i,1,3){
        cin>>x>>y;
        cout<<map[x][y]<<endl;
    }
    int loc=0;
    cin>>loc;
    if(loc<=3){
        foe(i,1,3){
            sum+=map[loc][i];
        }
    }
    else if(loc<=6){
        foe(i,1,3){
            sum+=map[i][loc-3];
        }
    }
    else if(loc==7){
        sum+=map[1][1]+map[2][2]+map[3][3];
    }
    else{
        sum+=map[1][3]+map[2][2]+map[3][1];
    }
    cout<<prise[sum-6]<<endl;
    return 0;
}