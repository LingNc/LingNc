#include <stdio.h>
#include <math.h>

int times(int num){
    int t=0,res=0;
    while(num){
        t++;
        if(num&1) res+=(int)pow(2,t)-1;
        num>>=1;
    }
    return res;
}

void solve(){
    int x,y;
    scanf("%lld %lld",&x,&y);
    printf("%lld\n",times(y+x)-times(x));
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}