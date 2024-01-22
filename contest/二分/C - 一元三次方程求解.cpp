#include<iostream>
#include<cmath>
using namespace std;
double f(double x);
double root(double x1,double x2);
double a,b,c,d;
int main(){
    cin>>a>>b>>c>>d;
    for(int i=-100;i<=100;i++){
        if(f(i)*f(i+1)<0||f(i)==0)
            printf("%.2lf ",root(i,i+1));
    }
    return 0;
}
double root(double x1,double x2){
    double mid;
    while(x2-x1>0.001){
        mid=(x1+x2)/2;
        if(f(mid)*f(x1)<=0)
            x2=mid;
        else
            x1=mid;
    }
    return x1;
}
double f(double x){
    return a*pow(x,3)+b*pow(x,2)+c*x+d;
}