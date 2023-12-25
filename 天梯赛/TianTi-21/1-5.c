#include<stdio.h>
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        double all,out,c;
        scanf("%lf %lf %lf",&all,&out,&c);
        c*=0.01;
        if(out>=c*all)
            printf("Yes");
        else
            printf("No");
        if(T!=0) printf("\n");
    }
    return 0;
}