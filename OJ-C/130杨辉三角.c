#include<stdio.h>
int C(int n,int m);
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<=n-1;i++){
        for(int j=0;j<=i;j++)
            printf("%d ",C(i,j));
        printf("\n");
    }
    return 0;
}
int C(int n,int m){
	int result=1;
	if(m!=0&&n!=0){
		int i=m+1,j=2;
		while(i<=n){
			result*=i;
			if(j<=n-m&&result%j==0){
				result/=j;
				j++;
			}
			i++;
		}
	}
	return result;
}