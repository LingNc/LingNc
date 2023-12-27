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
    int x,y;
    cin>>x>>y;
    double S=100*fabs(x-y)*0.5;
    cout<<S<<'\n';
    return 0;
}
