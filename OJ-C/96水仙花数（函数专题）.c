#include<stdio.h>
int narcissus(int num){
    int dis(int x,int n){
	    int i=n-1;
	    while(i>=1){
		    x=(x-x%10)/10;
		    i--;
	    }
	    x%=10;
        x=x*x*x;
	    return x;
    }
	if(num==dis(num,3)+dis(num,2)+dis(num,1))
		return 1;
	else
        return 0;
}

int main(){
    int m,n;
    while (scanf("%d %d",&m,&n)!=EOF){
        int flag=0;
        for (int i=m;i<=n;i++){
            if(narcissus(i)){
                printf("%d ",i);
                flag+=1;
            } 
        }
        if(flag==0) printf("no\n");
        else printf("\n");
    }
	return 0;
}
