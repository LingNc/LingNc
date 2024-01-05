#include<stdio.h>
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        int sum=0;
        while(n--){
            int t;
            scanf("%d",&t);
            sum+=t;
        }
        printf("%d\n",sum);
    }
    return 0;
}