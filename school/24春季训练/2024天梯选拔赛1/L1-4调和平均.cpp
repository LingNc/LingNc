#include<iostream>
#include<algorithm>
#include<cstring>
#define ll long long
#define endl '\n'
#define foe(i,a,b) for(int i=a;i<=b;i++)
#define foee(i,a1,b1,j,a2,b2) foe(i,a1,b1)foe(j,a2,b2)
using namespace std;

int main(){
    int n;
    cin>>n;
    double res=0,num;
    foe(i,0,n-1){
        cin>>num;
        res+=1/num;
    }
    res/=n;
    printf("%.2lf\n",1/res);
    return 0;
}