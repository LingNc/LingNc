本题可化简为每次可加1-3分，求加到第n分有几种方法，可以看作一种加强版的斐波那契数列，注意取模！！！

```c
#include<stdio.h>
using namespace std;
#define mod 1000000007 
long long a[1000010];  //防止爆int，开long long
int main()
{
	long long n;
	scanf("%lld",&n);
	a[1]=1;a[2]=2;a[3]=4;   //造斐波那契数列
	for(int i=4;i<=n;i++)
	{
		a[i]=(a[i-1]+a[i-2]+a[i-3])%mod;   //对1000000007取模
	}
	printf("%lld",a[n]);  
}
```