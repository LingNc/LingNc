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

int main(){
    int n;
    cin>>n;
    vector<double> price(n,0);
    double avg=0;
    foe(i,1,n){
        cin>>price[i-1];
        avg+=price[i-1];
    }
    if(n!=0) avg/=n;
    else return 0;
    foe(i,0,n-1){
        if(price[i]>avg){
            price[i]*=0.9;
        }
        printf("%.1lf",price[i]);
        if(i!=n-1) cout<<' ';
    }
    cout<<endl;
    return 0;
}