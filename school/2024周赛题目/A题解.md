A.唯一的马斯卡彭

两人为了达到自己的目的，都会选择最符合自己的想法的吃法，即zyfgg每次都会去吃最小的蛋糕，zcygg每次都会去吃最大的蛋糕，所以最后剩下的只会是大小居中的那个蛋糕。

解题思路：对所有蛋糕大小排序，输出第[n/2]+1小的蛋糕大小。

AC代码如下：

```
#include<stdio.h>
#include<stdlib.h>
int a[100004];
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

```
