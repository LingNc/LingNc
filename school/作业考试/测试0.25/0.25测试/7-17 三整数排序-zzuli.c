#include<stdio.h>
void main(){
    int x,y,z,t;
    scanf("%d %d %d",&x,&y,&z);
    if(y>x){t=x;x=y;y=t;}
    if(z>x){t=x;x=z;z=t;}
    if(z>y){t=y;y=z;z=t;}
    printf("%d %d %d",x,y,z);
}