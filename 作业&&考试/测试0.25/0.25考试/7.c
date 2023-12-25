#include<stdio.h>
int main(){
    int n,num,flag=1,max;
    scanf("%d",&n);
    
    scanf("%d",&num);
    max=num;
    for(int i=2;i<=n;i++){
        scanf("%d",&num);
        if(num>max){
            max=num;
            flag=1;
        }
        else if(max==num) flag+=1;
        else continue;
    }
    printf("%d %d",max,flag);
    return 0;
}