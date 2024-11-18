#include<stdio.h>

int main(){
	int a[10001]={0}; //初始化化数组作为环
	int n,m;//n代表总的人数，m代表报数到几退出
	scanf("%d%d",&n,&m);
	int count=0;//记录退出的个数
	int k=-1;//这里假定开始为第一个人，下标为0，编号为1，如需从编号x开始，则k=x-2
	while(count<n-1){  //总共需要退出n-1个人
		int i=0;//记录当前报数编号
		while(i<m){
			k=(k+1)%n; //循环处理下标
			if(a[k]==0){
				i++;
				if(i==m){
					a[k]=-1;
					count++;
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		if(a[i]==0){
			printf("%d\n",i+1);
			break;
		}
	}
	return 0;
}
