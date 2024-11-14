C.马斯卡彭之国

暴力破解不可取，复杂度极高，应采用二维数组存储该数字三角形，采用DP动态规划的方法，从底部回溯。

解题思路：先用二维数组a[i][j]存储(i,j)位置上的数字，从倒数第二行开始向上回溯，令a[i][j]表示从最底层到(i,j)位置的最大和，即令a[i][j]更新为其两个下层中最大数和自己的和，可得公式a[i][j]+=max(a[i-1][j],a[i-1][j+1]).

AC代码如下：

```
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
