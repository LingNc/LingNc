#include<stdio.h>
#include<math.h>

int prime(int n);
/**
 * 主函数
 *
 * 该函数首先读取一个整数n，然后判断n是否为素数。如果是素数，则输出"Yes"；否则输出"No"。
 *
 * @param 无
 * @return 总是返回0
 */
int main(){
    int n; // 定义变量n，用于存储输入的整数
    scanf("%d",&n); // 从标准输入读取一个整数到n
    if(prime(n)) printf("Yes"); // 如果n是素数，则输出"Yes"
    else printf("No"); // 如果n不是素数，则输出"No"
    return 0; // 程序正常结束，返回0
}

//素数
int prime(int n){
    if(n<=3) return 1;
    int sq=(int)sqrt(n);
    for(int i=2;i<=sq;i++){
        if(n%i==0) return 0;
    }
    return 1;
}