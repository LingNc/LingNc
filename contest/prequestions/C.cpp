#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    int list[110]={0};
    int floor=0;
    int num;
    int time=0;
    while(1){
        floor=0;
        time=0;
        cin>>n;
        if(n==0) break;
        for(int i=0;i<=n-1;i++){
            cin>>num;
            int m=num-floor;
            if(m<0){
                time+=4*m*(-1);
            }
            else{
                time+=6*m;
            }
            time+=5;
            floor=num;
        }
        cout<<time<<'\n';
    }
    return 0;
}