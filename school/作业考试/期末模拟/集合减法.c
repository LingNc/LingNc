#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"run.h"
int cmp(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}
int main(){
    start();
    int m,n;
    scanf("%d%d",&m,&n);
    int num[30000]={0};
    int A,B,max=0;
    for(int i=0;i<=m-1;i++){
        scanf("%d",&A);
        if(A>max) max=A;
        num[A]=1;
    }
    for(int i=0;i<=n-1;i++){
        scanf("%d",&B);
        if(num[B]!=0) num[B]=0;
    }
    for(int i=0;i<=max;i++){
        if(num[i])
            printf("%d ",i);
    }
    end();
    return 0;
}
    /*
    A[m],B[n];
    memset(A,0,sizeof(A));
    memset(B,0,sizeof(B));
    for(int i=0;i<=m-1;i++){
        scanf("%d",&A[i]);
    }
    for(int i=0;i<=n-1;i++){
        scanf("%d",&B[i]);
    }
    qsort(A,m,sizeof(int),cmp);
    qsort(B,n,sizeof(int),cmp);
    */