#include <math.h>
#include <stdio.h>
double a[100010];

int cal(double len){
    // 计算票价
    int ans=2;
    if(len>24){
        ans=6+ceil((len-24)/8);
    }
    else if(len>12){
        ans=4+ceil((len-12)/6);
    }
    else if(len>4){
        ans=2+ceil((len-4)/4);
    }
    return ans;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=2; i<=n; i++){
        scanf("%lf",&a[i]);
        // 前缀和
        a[i]+=a[i-1];
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        // 利用前缀和数组计算区间长度
        double len=fabs(a[x]-a[y]);
        int ans=cal(len);
            ans=ans<20?ans:20;
        printf("%d\n",ans);
    }
    return 0;
}