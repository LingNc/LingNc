#include<stdio.h>
#include<math.h>

int main(){
    int m,n,Pal(int);
    scanf("%d %d",&m,&n);
    for(int i=m;i<=n;i++){
        if(Pal(i)) printf("%d ",i);
    }
    return 0;
}

int Pal(int number){
    int len=(int)log10(number);
    int h=(int)pow(10,len),flag_0=0,flag_1=0,num=number;
    if(len%2==1) len++;
    for(int i=1;i<=len/2;i++){
        if(number/h==num%10) flag_1++;
        num%=h;
        num/=10;
        h/=100;
    }
    if(flag_1==len/2) flag_0=1;
    return flag_0;
}
