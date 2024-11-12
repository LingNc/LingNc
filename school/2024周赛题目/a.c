#include<stdio.h>
#include<stdlib.h>
int a[10004];
int cmp(const void *a,const void *b) {
	return *(int*)a-*(int*)b;
}
int main(){
    int t,n,i,m;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        qsort(a,n,sizeof(int),cmp);
        printf("%d\n",a[n/2]);
    }
    return 0;
}