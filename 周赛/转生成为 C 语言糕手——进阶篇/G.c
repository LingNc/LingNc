#include<stdio.h>
#include<math.h>

int price(double distant);
int plus(double distant,int num);

int main(){
    int n;
    scanf("%d",&n);
    double dis[n-1],distant;
    dis[0]=0;
    for(int i=1;i<=n-1;i++){
        scanf("%lf",&distant);
        if(i==1)
            dis[i]=distant;
        else
            dis[i]=dis[i-1]+distant;
    }
    int q,x,y;
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        scanf("%d %d",&x,&y);
        printf("%d\n",price(dis[y-1]-dis[x-1]));
    }
    return 0;
}
int price(double distant){
    int pce=0;
    if(distant<4)
        pce=2;
    else if(distant<12)
        pce=1+plus(distant,4);
    else if(distant<24)
        pce=2+plus(distant,6);
    else 
        pce=3+plus(distant,8);
    if(pce>=20) pce=20;
    return pce;
}
int plus(double distant,int num){
    if(distant/num-(int)(distant/num)>pow(10,-10))
        return (int)(distant/num)+1;
    else
        return (int)(distant/num);
}