//组合数
int C(int m,int n){
	int result=1;
	if(m!=0&&n!=0){
		int i=m+1,j=2;
		while(i<=n){
			result*=i;
			if(j<=n-m&&result%j==0){
				result/=j;
				j++;
			}
			i++;
		}
	}
	return result;
}
//逆转字符串
char *strrev(char *str){
    char *right = str,*left = str;
    char ch;
    while(*right)
        right++;
    right--;
    while(left<right){
        ch=*left;
        *left++=*right;
        *right--=ch;
    }
    return str;
}
//long long 阶乘
long long int factorial(long long int x){
	if(x==0||x==1) return 1;
	else return x*factorial(x-1);
}
//最大公约数
int gcd(int m,int n){
	while(1){
		if(m>n) m=m-n;
		else if(m<n) n=n-m;
		else break;
	}
	return n;
}
//整数循环移动一个
int *ringOne(int *a,int n){
    int t=a[n-1];
    for(int i=n-1;i>=1;i--){
        a[i]=a[i-1];
    }
    a[0]=t;
    return a;
}
//字符串循环移动
#include<string.h>
char *ringOne(char *str){
    int len=strlen(str);
    char t=str[len-1];
    for(int i=len-1;i>=1;i--){
        str[i]=str[i-1];
    }
    str[0]=t;
    return str;
}

#include<time.h>
#include<stdio.h>
static clock_t start_time;
//计算用时开始
clock_t start(){
    start_time=clock();
    return start_time;
}
//计算用时结束
/*
double end(clock_t start){
    clock_t end=clock();
    double Times=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\nThis time: %.3lfms",Times*1000);
    return Times;
}
*/
//计算用时结束
double end(){
    clock_t end=clock();
    double Times=(double)(end-start_time)/CLOCKS_PER_SEC;
    printf("\nThis time: %.3lfms\n",Times*1000);
    return Times;
}