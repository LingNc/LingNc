#include<stdio.h>
int gcb(int x,int y){
	if(x==0||y==0) return x=(x==0)?y:x;
	if(x>y){
		x=x%y;
		return gcb(y,x);
	}
	else{
		y=y%x;
		return gcb(x,y);
	}
}
	
int main(){
	int m,n;
	scanf("%d %d",&m,&n);
	printf("%d",gcb(m,n));
	return 0;
}
