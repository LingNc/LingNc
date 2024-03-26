#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
#define ll long long
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'

using namespace std;
double f(int x,double avg);
int main(){
    int n;
    cin>>n;
    vector<int> num(n,0);
    double avg=0;
    foe(i,0,n-1){
        cin>>num[i];
        avg+=num[i];
    }
    avg/=(double)n;
    double res=0;
    foe(i,0,n-1){
        res+=f(num[i],avg);
    }
    res=sqrt(res/n);
    printf("%.5lf\n",res);
    return 0;
}
double f(int x,double avg){
    return ((double)x-avg)*((double)x-avg);
}