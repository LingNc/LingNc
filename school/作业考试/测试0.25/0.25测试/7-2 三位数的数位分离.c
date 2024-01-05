#include<stdio.h>
#include<math.h>
int main(){
	int n,len;
	scanf("%d",&n);
	len=log10(n)+1;
	for(int i=1;i<=len;i++){
        if(i<=len-1) printf("%d ",n%10);
        else printf("%d",n%10);
		n=(n-n%10)/10;
	}
	return 0;
}
