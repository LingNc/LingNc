#include<stdio.h>
int main(){
	int max(int x){
		int z;
		scanf("%d",&z);
		if(z>0){
			if(x>=z) return max(x);
			else return max(z);
		}
		else return x;
	}
	int y;
	scanf("%d",&y);
	printf("%d",max(y));
	return 0;
}
