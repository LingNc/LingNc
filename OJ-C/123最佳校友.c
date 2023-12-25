#include<stdio.h>
int main(){
    int b[100]={0};
    while(1){
        int num;
        scanf("%d",&num);
        if(num<0) break;
        b[num]++;
    }
    int max=b[0];
    for(int i=1;i<=99;i++)
        if(b[i]>max) 
            max=b[i];
    for(int i=0;i<=99;i++)
        if(b[i]==max)
            printf("%d ",i);
    return 0;
}