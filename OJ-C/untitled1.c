#include<stdio.h>
int main(){
	int N;
	while(1){
		if(scanf("%d",&N)==1){ //修改循环条件
			int floor=0,number=0; //初始化变量
			for(int i=0;i<=N/2;i++){ //修改循环范围
				floor=i*2; //初始化floor为i*2
				for(int j=1;j<=N-i*2;j++){
					floor+=1;
					if(floor==N) number+=1; //判断是否等于N
					if(floor>N) break; //判断是否大于N
				}
			}
			printf("%d\n",number);
		}
		else break;
	}
	return 0;
}

