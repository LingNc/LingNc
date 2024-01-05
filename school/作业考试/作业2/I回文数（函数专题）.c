#include<stdio.h>
int inverse(int n);
int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    for(int i=m;i<=n;i++){
        if(inverse(i)==i)
            printf("%d ",i);
    }
    return 0;
}
int inverse(int n){
    int num=n,result=0;
    while(num){
        result=10*(num%10+result);
        num/=10;
    }
    return result/10;
}