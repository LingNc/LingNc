#include <stdio.h>
#include <string.h>
int main(){
	char a[1004];
	int n,m,i;
	scanf("%d",&n);
	scanf("%s",a);
	for(i=0;i<n;i++){
		if(a[i]>='a')//判断该字符是大写还是小写
		a[i]=a[i]-32;
		else a[i]=a[i]+32;
	}
	printf("%s",a);
	return 0;
}