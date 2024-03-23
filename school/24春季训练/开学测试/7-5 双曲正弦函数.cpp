#include<iostream>
#include<algorithm>
#include<cmath>
#define ll long long
#define endl '\n'
#define foe(i,a,b) for(ll i=a;i<=b;i++)
#define foee(i,a1,b1,j,a2,b2) foe(i,a1,b1)foe(j,a2,b2)
using namespace std;
double f(double x,double e);
int main(){
    double x,e,y;
    cin>>x>>e;
    printf("%.6f\n",f(x,e));
    return 0;
}
double f(double x,double e){
    double res=0;
    for(int i=1;;i+=2){
        double mid=1;
        for(double j=1;j<=i;j++){
            mid*=x/j;
        }
        res+=mid;
        if(fabs(mid)<e) break;
    }
    return res;
}