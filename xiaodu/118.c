#include<stdio.h>
void insert(int a[],int n,int num);
void PrintArr(int a[],int n);
int main(){
	int n,i;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int num;
	scanf("%d",&num);
	insert(a,n,num);
	PrintArr(a,n);
	printf("%d",a[n]);

	return 0;
}
void PrintArr(int a[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
}
void insert(int a[],int n,int num){
	int i=0;
	while(a[i]<num){
		i++;
	}
	if(a[n-1]<num) i++;
	int j;
	int b[n+1];
	for(j=0;j<i;j++){
		b[j]=a[j];
	}
	b[j]=num;
	j++;
	for(;j<n+1;j++){
		b[j]=a[j-1];
	}
	int h;
	for(h=0;h<n+1;h++){
		a[h]=b[h];
	}
}