#include<cstring>
#include<cstdio>
#include<cmath>
#include<iostream>
#include<climits>
using namespace std;
bool hw(int x);
int main(){
    int n;
    cin>>n;
    int i=n+1;
    while(1){
        if(hw(i)) break;
        i++;
    }
    cout<<i<<'\n';
    return 0;
}
bool hw(int x){
    int sum=0,start=x;
    while(x>0){
        sum=sum*10+x%10;
        x/=10;
    }
    return (start==sum)?1:0;
}
