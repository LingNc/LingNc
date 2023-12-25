#include<stdio.h>
int three(int m){
    return m*m*m;
}
int main(){
    int num,flower;
    scanf("%d",&num);
    flower=three(num%10)+three((num/10)%10)+three(num/100);
    if(flower==num) printf("yes");
    else printf("no");
    return 0;
}