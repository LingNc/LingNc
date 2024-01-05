#include<stdio.h>
#include"run.h"
int main(){
    start();
    int n,m,i,j,a[10001],b[10001];
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(j=0;j<m;j++){
        scanf("%d",&b[j]);
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(a[i]>a[j]){
                int t=a[j];
                a[j]=a[i];
                a[i]=t;
            }
        }
    }
    for(i=0;i<m;i++){
        for(j=i+1;j<m;j++){
            if(b[i]>b[j]){
                int t=b[j];
                b[j]=b[i];
                b[i]=t;
            }
        }
    }
    int k=0,c;
    for(i=0;i<n;i++){
        c=0;
        for(j=0;j<m;j++){
            if(a[i]==b[j]){
                a[i]=-1;
                k++;
                c=1;
                continue;
            }
        }
        if(c==0)
            printf("%d ",a[i]);
    }
    if(k==n)
        printf("0");
    end();
    return 0;
}