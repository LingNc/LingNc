# A 唯一的马斯卡彭

### 解题思路

两人为了达到自己的目的，都会选择最符合自己的想法的吃法，即zyfgg每次都会去吃最小的蛋糕，zcygg每次都会去吃最大的蛋糕，所以最后剩下的只会是大小居中的那个蛋糕。
首先对所有蛋糕大小进行排序。然后zyfgg和zcygg的策略会导致最后剩下的蛋糕是排序后的中间值。如果 $ n $ 是偶数，剩下的蛋糕是第 $ \frac{n}{2} $ 个；如果 $ n $ 是奇数，剩下的蛋糕是第 $ \frac{n}{2} $ 个。输出排序后的第 $ \left\lfloor \frac{n}{2} \right\rfloor $ 个蛋糕的大小。

### 解题过程：

对所有蛋糕大小排序，输出第 $ \left\lfloor \frac{n}{2} \right\rfloor + 1 $ 小的蛋糕大小。

**注意：如果使用时间复杂度为$O(n^2)$的代码会时间超限，请使用更高效的算法**

## AC代码

```c
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
