# I 心急吃不了马斯卡彭

将输入字符串中的每个字母的大小写进行反转。

### AC代码

```c
#include <stdio.h>
#include <string.h>
int main(){
	char str[1004];
	int n,m,i;
	scanf("%d",&n);
	scanf("%s",str);
	for(i=0;i<n;i++){
		if(str[i]>='a')//判断该字符是大写还是小写
		    str[i]=str[i]-32;
		else
            str[i]=str[i]+32;
	}
	printf("%s",str);
	return 0;
}
```