#include <stdio.h>
#include<stdlib.h>
int main(){
    int n,i,s;
    scanf("%d",&n);
    int *a=(int*)malloc((n+1)*sizeof(int));
    for(i=1; i<=n; i++)
        a[i]=i;
    s=n;
    while(s>0){
        for(i=s; i>=1; i--){
            if(2*i<=n){
                a[i]=a[2*i];
            }
        }
        s=s/2;
    }
    printf("%d",a[1]);
    return 0;
}