#include<cstring>
#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
int main(){
    long long a;
    int b;
    cin>>a>>b;
    int len=(int)log10(a)+1;
    int num=0,t;
    for(int i=0;i<=len-1;i++){
        t=a%10;
        a/=10;
        if(t==b)
            num++;
    }
    cout<<num<<'\n';
    return 0;
}