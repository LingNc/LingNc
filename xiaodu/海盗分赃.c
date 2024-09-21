#include<stdio.h>

int main(){
    int P,D;
    scanf("%d%d",&P,&D);
    int res;
    if(P==3) res=D-1;
    else res=D-(P/2+1);
    printf("%d\n",res);
    return 0;
}