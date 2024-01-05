#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<climits>
#include<string>
using namespace std;
void h(int* time);
int main(){
    int m;
    cin>>m;
    int time[10000];
    while(m--){
        h(time);
    }
    return 0;
}
void h(int* time){
        int n;
        cin>>n;
        int num=0;
        memset(time,0,10000*sizeof(int));
        for(int i=1;i<=n;i++){
            int Bi,Ei;
            cin>>Bi>>Ei;
            int flag=1;
            for(int i=Bi+1;i<Ei;i++){
                if(time[i]==1){
                    flag=0;
                    break;
                }
            }
            if(flag==1){
                num++;
                if(n==0) break;
                for(int i=Bi;i<=Ei;i++){
                    time[i]=1;
                }
            }
        }
        printf("%d\n",num);
}