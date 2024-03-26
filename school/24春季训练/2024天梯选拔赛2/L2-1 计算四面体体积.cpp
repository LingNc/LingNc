#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
#include<climits>
#include<cstdlib>
#define ll long long
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'
#define pi 3.1415926535

using namespace std;
double V(double a,double b,double c,double ca,double cb,double cy);
int main(){
    int A,B,C;
    string str;
    int ca,cb,cy;
    cin>>A>>B>>C;
    foe(i,0,2){
        cin>>str;
        string s1(str.begin()+3,str.end());
        if(i==0) ca=stod(s1.c_str());
        if(i==1) cb=stod(s1.c_str());
        if(i==2) cy=stod(s1.c_str());
    }
    printf("%.2lf\n",V(A,B,C,ca,cb,cy));
    return 0;
}
double V(double a,double b,double c,double ca,double cb,double cy){
    ca=pi/ca;
    cb=pi/cb;
    cy=pi/cy;
    return 1/(1.0*6)*a*b*c*sqrt(1-cos(ca)*cos(ca)-cos(cb)*cos(cb)-cos(cy)*cos(cy)+2*cos(ca)*cos(cb)*cos(cy));
}