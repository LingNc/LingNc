#include<stdio.h>
int is_prime(int num){
    int flag=0;
    if(num==2) flag=1;
    else if(num>2){
        for(int i=3;i<=num/2;i+=1){
            if(num%i==0){
                flag=0;
                break;
            }
            else flag=1;
        }
    }
    return flag;
}
int main(){
    int flag=0,A,B;
    scanf("%d %d",&A,&B);
    if(A>=0&&B>=0){
        for(int i=A+1;i<B;i++){
            if(is_prime(i)) flag+=1;
        }
        printf("%d",flag);
    }
    return 0;
}