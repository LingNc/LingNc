#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void LargestTwo(int a[],int n,int* pfirst,int* psecond);
int cmp(const void *p1,const void *p2){
    return *(int*)p2-*(int*)p1;
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    memset(a,0,n*sizeof(int));
    int len=n;
    while(n--){
        scanf("%d",&a[n]);
    }
    int max1,max2;
    int *p1=&max1,*p2=&max2;
    LargestTwo(a,len,p1,p2);
    printf("%d %d",max1,max2);
    return 0;
}
void LargestTwo(int a[],int n,int* pfirst,int* psecond){
    /*数组a有n个元素，将数组中的最大值存入形参指针pfirst所指内存单元，将数组中第二大的值存入形参指针psecond所指内存单元。 */
    qsort(a,n,sizeof(int),cmp);
    *pfirst=a[0];
    *psecond=a[1];
}