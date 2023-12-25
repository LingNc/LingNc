#include<stdio.h>
int main(){
	long long int gcd,lcm,m,n;
	scanf("%lld %lld",&m,&n);
	lcm=m*n;
	while(1){
		if(m>n) m=m-n;
		else if(m<n) n=n-m;
		else{
			gcd=n;
			break;
		}
	}
	lcm=lcm/gcd;
	printf("%lld %lld",gcd,lcm);
	return 0;
}
