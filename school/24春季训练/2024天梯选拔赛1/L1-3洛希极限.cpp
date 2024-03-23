#include<iostream>
#include<algorithm>
#define ll long long
#define endl '\n'
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define foee(i,a1,b1,j,a2,b2) foe(i,a1,b1)foe(j,a2,b2)
using namespace std;

int main(){
    double p,dis;
    bool s;
    cin>>p>>s>>dis;
    double res;
    res=(s)?p*1.26:p*2.455;
    if(res>=dis) printf("%.2lf T_T\n",res);
    else printf("%.2lf ^_^\n",res);
    return 0;
}