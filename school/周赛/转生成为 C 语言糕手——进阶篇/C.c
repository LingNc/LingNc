#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    scanf("%d",&n);
    int level[n],my,distant,min,flag=0;
    for(int i=0;i<=n-1;i++) scanf("%d",&level[i]);
    scanf("%d",&my);
    distant=abs(level[0]-my);
    for(int i=1;i<=n-1;i++){
        min=abs(level[i]-my);
        if(distant>min){
            distant=min;
            flag=i;
        }
    }
    printf("%d",level[flag]);
    return 0;
}