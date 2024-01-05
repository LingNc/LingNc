#include<stdio.h>
int gcd(int n,int m);
int max(int x,int y);
int min(int x,int y);
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    printf("%d",gcd(max(n,m),min(m,n)));
    return 0;
}
int gcd(int n,int m){
    int r=n-m;
    if(r==0) return n;
    else
        return gcd(max(m,r),min(m,r));
}
int max(int x,int y){
    return (x>y)?x:y;
}
int min(int x,int y){
    return (x<y)?x:y;
}