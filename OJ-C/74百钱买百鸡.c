#include<stdio.h>
#include<math.h>
int main(){
	int roo=0,hen,n,flag=0;
	scanf("%d",&n);
	while(1){
		hen=n-7*roo;
		if(hen%4==0&&hen!=0&&hen>0){
			printf("%4d%4d%4d\n",(int)roo,(int)hen/4,(int)(n-(roo+hen/4)));
			roo+=1;
			flag+=1;
			continue;
		}
			else if(hen>0&&(hen%4)!=0){
			roo+=1;
			continue;
		}
		else if(hen==0||flag>0) break;
		else{
		printf("No Answer"); 
		break;
		}
	}
	return 0;
}
