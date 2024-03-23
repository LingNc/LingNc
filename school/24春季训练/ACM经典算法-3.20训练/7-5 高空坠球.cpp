#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
#define ll long long
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'

using namespace std;

int main(){
    double a1=1,q=0.5,n,h;
    cin>>h>>n;
    double Sn=0,hn=0;
    /*
    foe(i,1,n){
        if(i==1){
            Sn+=h;
            hn=h;
            h/=2;
        }
        else if(i==n){
            Sn+=h;
            hn=h;
        }
        else{
            Sn+=2*h;
            hn=h;
            h/=2;
        }
    }*/
    if(n==0)
        printf("%.1lf %.1lf",0,0);
    else
        printf("%.1lf %.1lf",h*(pow(q,n-1)-1)/(q-1)+h*0.5*(pow(q,n-1)-1)/(q-1)+pow(q,n)*h*2,a1*pow(q,n)*h);
    return 0;
}