#include<stdio.h>
#include<stdlib.h>
int a[100004];
int cmp(const void *a,const void *b){
    return *(int *)a-*(int *)b;
}
int main(){
    int t,n,i,m;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        // for(int i=0;i<n-1;i++){
        //     for(int j=0;j<n-1-i;j++){
        //         if(a[j]>a[j+1]){
        //             auto t=a[j];
        //             a[j]=a[j+1];
        //             a[j+1]=t;
        //         }
        //     }
        // }
        qsort(a,n,sizeof(int),cmp);
        printf("%d\n",a[n/2]);
    }
    return 0;
}