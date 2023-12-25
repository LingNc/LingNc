int is_prime(int n){
	int flag=0;
	if(n<=3) flag=(n==1)?0:1;
	else{
		for(int i=3;i<=n/2;i+=2){
			if(n%i==0||(n%6!=1&&n%6!=5)||n%2==0){
				flag=0;
				break;				
			}
			else flag=1;
		}
	}
	return flag;
}
