#include<stdio.h>
int flag=0;
int three_n(long long int n){
    if(n==1) return flag;
    else if(n%2==0){
        flag+=1;
        three_n(n/2);
    }
    else{
        flag+=1;
        three_n(3*n+1);
    }
}
int main(){
    while(1){
        flag=0;
        int n;
        if(scanf("%d",&n)==EOF) break;
        printf("%d\n",three_n(n));
    }
    return 0;
}