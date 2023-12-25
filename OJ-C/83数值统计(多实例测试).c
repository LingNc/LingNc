#include<stdio.h>
int main(){
	int n,a,b,c;
	double num;
	while(1){
		a=b=c=0;
		scanf("%d",&n);
		if(n==0) break;
		for(int i=1;i<=n;i++){
			scanf("%lf",&num);
			if(num<0) a++;
			else if(num>0) c++;
			else b++;
		}
		printf("%d %d %d\n",a,b,c);
	}
	return 0;
}
