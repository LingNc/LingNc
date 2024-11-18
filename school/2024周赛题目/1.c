#include<stdio.h>

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int x,y;
        scanf("%d %d",&x,&y);
        printf("%d\n",y*2-__builtin_popcount(x+y)+__builtin_popcount(x));
    }
    return 0;
}