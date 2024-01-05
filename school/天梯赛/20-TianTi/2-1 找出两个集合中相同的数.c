#include<stdio.h>
#include<stdlib.h>
int cmp(const void* p1,const void* p2){
    return *(int*)p1-*(int*)p2;
}
int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    int M[m],N[n];
    for(int i=0;i<=m-1;i++){
        scanf("%d",&M[i]);
    }
    for(int i=0;i<=n-1;i++){
        N[i]=0;
    }
    int num,* p=N,k=0;
    for(int i=0;i<=n-1;i++){
        scanf("%d",&num);
        for(int i=0;i<=m-1;i++){
            if(M[i]==num){
                *(p++)=num;
                k++;
            }
        }
    }
    qsort(N,k,sizeof(int),cmp);
    for(int i=0;i<=k-1;i++){
        if(N[i]<=0) break;
        printf("%d ",N[i]);
    }
    return 0;
}