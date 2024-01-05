#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int flag=0,city=-1;
    for(int i=0;i<=n-1;i++){
        int la_ty=city;
        scanf("%d",&city);
        if(la_ty!=0&&city==0)
            flag++;
    }
    printf("%d",flag);
    return 0;
}