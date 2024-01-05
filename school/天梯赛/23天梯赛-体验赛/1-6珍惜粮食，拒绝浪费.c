#include<stdio.h>
int main(){
    int year,g,cost=0;
    scanf("%d %d",&year,&g);
    if(year<=6) cost+=10;
    else if(year<=12) cost+=39;
    else cost+=78;
    cost+=10*(g/250);
    printf("%d\n",cost);
    return 0;
}