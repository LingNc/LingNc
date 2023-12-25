#include<stdio.h>
int is_prime(int number){
    int flag;
    if(number==2||number==3){
        flag=1;
        goto prime_end;
    }
    if(number%2==0&&number>2) flag=0; 
    else{
        for(int i=3;i<(number+1)/2;i++){
            if(number%i==0){
                flag=0;
                break;
            }
            else flag=1;
        }
    }
    prime_end:
    return flag;
}
int main(){
    int flag=0,A,B;
    scanf("%d %d",&A,&B);
    if(A<0||B<0) goto main_end;
    for(int i=A+1;i<=B-1;i++){
        if(is_prime(i)) flag+=1;
    }
    printf("%d",flag);
    main_end:
    return 0;
}