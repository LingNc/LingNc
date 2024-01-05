#include<stdio.h>

int main(){
    int n;
    while(scanf("%d",&n),n!=0){
        int num,result;
        scanf("%d",&result);
        for(int i=2;i<=n;i++){
            scanf("%d",&num);
            result^=num;
        }
        printf("%d\n",result);
    }
    return 0;
}