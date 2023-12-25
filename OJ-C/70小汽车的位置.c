#include<stdio.h>
int turn_det(int now,int comd){
	int turn;
	if(comd==1) turn=-1;
	else turn=1;
	now+=turn;
	if(now>=4) now-=4;
	else if(now<=-1) now+=4;
	return now;
}
int main(){
	int locate[2]={0,0},direction=0,time_0=0,time_1,comd;
	while(1){
		scanf("%d\n%d",&time_1,&comd);
		int distant=10*(time_1-time_0);
		if(direction==0) locate[1]+=distant;
		else if (direction==1) locate[0]+=distant;
		else if (direction==2) locate[1]-=distant;
		else locate[0]-=distant;
		time_0=time_1;
		if(comd==3) break;
		direction=turn_det(direction,comd);
	}
	printf("%d %d",locate[0],locate[1]);
}