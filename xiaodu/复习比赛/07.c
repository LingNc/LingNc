#include<stdio.h>


int main(){
    while(1){
        int m,n;
        if(scanf("%d%d",&m,&n)==EOF)
            break;
        printf("%d\n",(m>n)?m:n);
    }
    return 0;
}