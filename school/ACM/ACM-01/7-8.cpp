#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<climits>
#include<string>
using namespace std;

int main(){
    int N;
    cin>>N;
    double sum=1,k=4,flag=-1;
    for(int i=2;i<=N;i++){
        sum+=flag*(1/k);
        flag*=-1;
        k+=3;
    }
    printf("sum = %.3lf",sum);
    return 0;
}
