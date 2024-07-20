#include<stdio.h>

int sum(int x);
int main(){
    for(int i=100;i<=200;i++){
        if(sum(i)==6){
            printf("%d\n",i);
        }
    }
    return 0;
}
int sum(int x){
    int s=0;
    while(x){
        s+=x%10;
        x/=10;
    }
    return s;
}