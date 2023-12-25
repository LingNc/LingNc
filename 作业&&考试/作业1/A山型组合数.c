#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int num[3];
        for(int i=0;i<=2;i++)
            scanf("%d",&num[i]);
        int flag=0;
        if(num[0]>num[1]){
            if(num[2]==num[1])
                flag=1;
            else
                flag=0;
        }
        else if(num[0]<num[1]){
            if(num[2]==num[0])
                flag=1;
            else
                flag=0;
        }
        else{
            if(num[2]>num[0])
                flag=1;
            else
                flag=0;
        }
        if(flag)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}