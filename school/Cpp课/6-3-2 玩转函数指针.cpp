// 一个可能的函数被调用进行测试的例子像这样：
// ** 注意： 实际的测试程序可能与下面这个程序很不同！
#include <stdio.h>
void isFactorOf(int x, int y){
    if(x % y) printf("%d is not a factor of %d.\n", y, x);
    else printf("%d is a factor of %d.\n", y, x);
}
void proceed(int *a, int *b, int size, void (*fp)(int x, int y));
int main()
{
    int n;
    scanf("%d", &n);
    int a[n], b[n];
    for(int i=0; i<n; i++) scanf("%d", a+i);
    for(int i=0; i<n; i++) scanf("%d", b+i);
    proceed(a, b, n, isFactorOf);
    return 0;
}
/* 你的代码将被嵌到这里 */
void proceed(int *a,int *b,int size,void (*fp)(int x,int y)){
    for(int i=0;i<=size-1;i++){
        fp(a[i],b[i]);
    }
}