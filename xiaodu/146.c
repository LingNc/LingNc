#include<stdio.h>
void solve(){
	int n,m,a[10000],max,sum=0;
	scanf("%d",&m);
	int j;
	for(j=0;j<m;j++)
		scanf("%d",&a[j]);
	max=a[0];
	for(j=0;j<m;j++)
		if(a[j]>max)
			max=a[j];
	for(j=0;j<m;j++)
		if(a[j]!=max)
			sum=sum+a[j];
	if(sum>=max-1)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	
	return 0;
}