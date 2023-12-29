#include<cstring>
#include<cstdio>
#include<cmath>
#include<iostream>
#include<climits>
#include<string>
using namespace std;

int main(){
    int n,s,q;
    cin>>n>>s>>q;
    int rain[n+1];
    rain[0]=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&rain[i]);
    }
    /*
    int b_rain[n];
    for(int i=1;i<=n;i++){
        b_rain[i]=rain[i]-rain[i-1];
    }
    */
   //s
    for(int i=1;i<=s;i++){
        int k,L;
        scanf("%d %d",&k,&L);
        rain[k]+=L;
    }
    int sum_r[n+1];
    sum_r[0]=0;
    for(int i=1;i<=n;i++){
        sum_r[i]=sum_r[i-1]+rain[i];
    }
    //q
    for(int i=1;i<=q;i++){
        int l,r;
        scanf("%d %d",&l,&r);
        printf("%d\n",sum_r[r]-sum_r[l-1]);
    }
    return 0;
}
