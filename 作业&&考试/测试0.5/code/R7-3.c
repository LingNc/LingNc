#include<stdio.h>
int have_7(int n);
int main(){
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        int N;
        scanf("%d",&N);
        for(int i=1;i<=N;i++){
            if(i%7==0||have_7(i))
                printf("%d ",i);
        }
        printf("\n");
    }
    return 0;
}
int have_7(int n){
    int num=n,flag=0;
    while(1){
        if(num==0) break;
        if(num%10==7) flag++;
        num/=10;
    }
    return flag;
}