#include<iostream>
#include<cstdio>

bool check(int x);
int L,N,M;
int distant[50010]={ 0 };

int main(){
    scanf("%d %d %d",&L,&N,&M);
    for(int i=1;i<=N;i++){
        scanf("%d",&distant[i]);
    }
    distant[N+1]=L;

    //二分法
    int start=0,end=L+1,mid=0;
    while(start+1<end){
        mid=(start+end)>>1;
        if(check(mid))
            start=mid;
        else
            end=mid;
    }

    printf("%d\n",start);
    return 0;
}
bool check(int x){
    int cnt=0,last=0;
    for(int i=1;i<=N+1;i++)
        if(distant[i]-last<x){
            cnt++;
            if(cnt>=M+1) break;
        }
        else
            last=distant[i];
    return cnt<=M;
}
/*
0 2 11 14 17 22 25
0 2 9  3  3  5  3
0   11    6  5  3
0 2 3  9  16 22 25
25 5 2
2 3 9 16 22
*/
