#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"run.h"

int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    int p[m][n];
    memset(p,0,sizeof(p));
    int* ptr=&p[0][0];
    for(int i=0;i<=m*n-1;i++){
        scanf("%d",&ptr[i]);
    }
    int sum=0;
    int i=0;
    while(i<=m*n-1){
        if(i<=n-1){
            sum+=ptr[i];
            i++;
        }
        else if(i<=(m-1)*n-1){
            sum+=ptr[i];
            if(n>=2){
                i+=n-1;
                sum+=ptr[i];
            }
            i++;
        }
        else{
            sum+=ptr[i];
            i++;
        }
    }
    printf("%d\n",sum);
    return 0;
}