#include<stdio.h>
int main(){
	char pai[13]="A23456789TJQK";
    int n;
    scanf("%d",&n);
    if(n>13||n<1){
        printf("none\n");
        return 0;
    }
    printf("%c\n",pai[n-1]);
	return 0;
}