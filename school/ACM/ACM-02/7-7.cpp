#include<cstring>
#include<cstdio>
#include<cmath>
#include<iostream>
#include<climits>
using namespace std;
int main(){
    int n;
    long long int ji=0,ou=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        if(i%2)
            ji+=i;
        else
            ou+=i;
    }
    printf("%lld\n%lld",ji,ou);
    return 0;
}
