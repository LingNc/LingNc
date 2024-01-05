int C(int m,int n){
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
