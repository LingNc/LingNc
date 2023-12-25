#include<stdio.h>

int left(int floor1,int floor2);

int main(){
    int n;
    scanf("%d",&n);
    int a[n+1];
    a[0]=0;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int s=0;
    for(int i=0;i<=n-1;i++)
        s+=left(a[i],a[i+1]);
    printf("%d",s);
    return 0;
}
int left(int floor1,int floor2){
    int s=0;
    if(floor2-floor1>0)
        s+=6*(floor2-floor1)+5;
    else
        s+=4*(floor1-floor2)+5;
    return s;
}