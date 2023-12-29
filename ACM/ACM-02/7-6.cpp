#include<cstring>
#include<cstdio>
#include<cmath>
#include<iostream>
#include<climits>
using namespace std;
int main(){
    int n;
    cin>>n;
    int num[n];
    memset(num,0,n*sizeof(int));
    int max=INT_MIN,k=0;
    for(int i=0;i<=n-1;i++){
        scanf("%d",&num[i]);
        if(num[i]>max){
            max=num[i];
            k=i;
        }
    }
    max=INT_MIN;
    for(int i=0;i<=n-1;i++){
        if(i!=k){
            if(num[i]>max){
                max=num[i];
            }
        }
    }
    cout<<max<<'\n';
    return 0;
}
