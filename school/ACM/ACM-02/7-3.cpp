#include<cstring>
#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
int main(){
    long long int R0,N,num_i=0;
    cin>>N>>R0;
    int t=0;
    while(N>num_i){
        num_i+=(int)pow(R0,t);
        t++;
    }
    cout<<t<<'\n';
    return 0;
}
