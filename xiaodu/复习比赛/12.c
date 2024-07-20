#include<stdio.h>


int main(){
    int n;
    while(1){
        if(scanf("%d",&n)==EOF) break;
        if(n%3==0)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}