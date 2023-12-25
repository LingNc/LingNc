#include<stdio.h>
#include<math.h>
int is_flower(int n);
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int sum=0;
    for(int i=n;i<=m;i++){
        if(is_flower(i)) sum++;
    }
    printf("%d",sum);
    return 0;
}
int is_flower(int n){
    int h=(int)log10(n);
    int sum=0;
    int num=n;
    for(int i=1;i<=h+1;i++){
        sum+=(num%10)*(num%10)*(num%10);
        num/=10;
    }
    if(sum==n) return 1;
    else return 0;
}