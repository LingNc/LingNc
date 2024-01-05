#include<cstring>
#include<cstdio>
#include<cmath>
#include<iostream>
#include<climits>
#include<string>
using namespace std;
int row[100001]={0},col[100001]={0};
int main(){
    int N,M,Q;
    cin>>N>>M>>Q;
    int r=0,c=0;
    for(int i=0;i<=Q-1;i++){
        int n,m;
        scanf("%d %d",&n,&m);
        if(n==0){
            if(row[m]==0) r++;
            row[m]+=1;
        }
        else{
            if(col[m]==0) c++;
            col[m]+=1;
        }
    }
    cout<<(N-r)*(M-c);
    return 0;
}
