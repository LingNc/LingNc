#include<stdio.h>
#include<math.h>
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        int q=sqrt(n);
        for(int i=2;i<=q;i++){
            if(n%i==0){
                printf("%d\n",n/i);
                break;
            }
        }
    }
    return 0;
}