#include<stdio.h>
int MaxNum(int m,int n);
int main(){
    int m,n;
    while(1){
        scanf("%d %d",&m,&n);
        if(m==0&&n==0) return 0;
        printf("%d\n",MaxNum(m,n));
    }
    return 0;
}
int MaxNum(int m,int n){
    if(m>n)
        return m*100+n;
    else
        return n*100+m;
}