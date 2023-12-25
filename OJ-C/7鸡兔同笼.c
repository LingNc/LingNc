#include<stdio.h>
int main(){
	int heads,feet,chicken,rabbit;
	scanf("%d %d",&heads,&feet);
	chicken=2*heads-feet/2;
	rabbit=feet/2-heads;
	printf("%d %d",chicken,rabbit);
	return 0;
}
