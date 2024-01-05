#include<stdio.h>
int good(int num,int n);
int main(){
    int m,n;
    scanf("%d %d",&n,&m);
    if(good(n,m))
        printf("YES");
    else
        printf("NO");
    return 0;
}
int good(int n,int num){
    int m=num;
    if(m==1||n==1){
        return (m!=1&&n==1)?0:1;
    }
    while(1){
        if(m%n!=0)
            return 0;
        else{
            m/=n;
            if(m==0||m==1) return 1;
        }
    }
}