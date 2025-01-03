# C 马斯卡彭之王

### 解题思路

题目要求马斯卡彭之王在回宫的路上吃到最多的马斯卡彭蛋糕。由于每次只能向上走一层，因此需要找到一条从底部到顶部的路径，使得路径上的蛋糕数量之和最大。

我们可以使用动态规划（DP）来解决这个问题。具体思路如下：

1. **状态定义**：用二维数组 `a[i][j]` 存储第 `i` 行第 `j` 列位置上的蛋糕数量。
2. **状态转移**：从倒数第二行开始向上回溯，更新每个位置的最大和。具体来说，对于每个位置 `(i, j)`，其最大和为当前位置的蛋糕数量加上其下方两个位置中较大的那个位置的最大和。即：
   $$ a[i][j] = a[i][j] + \max(a[i+1][j], a[i+1][j+1]) $$
3. **最终结果**：最终 `a[0][0]` 即为从底部到顶部的最大蛋糕数量之和。

### 解题过程

1. 读取输入数据，将每个位置的蛋糕数量存储在二维数组 `a` 中。
2. 从倒数第二行开始，向上回溯更新每个位置的最大和。
3. 输出 `a[0][0]`，即从底部到顶部的最大蛋糕数量之和。

### AC代码

```c
#include<stdio.h>
#include<math.h>
int a[1005][1005];
int main() {
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=n-2;i>=0;i--){
        for(j=0;j<=i;j++){
            a[i][j]+=fmax(a[i+1][j],a[i+1][j+1]);
        }
    }
    printf("%d",a[0][0]);
    return 0;
}
```