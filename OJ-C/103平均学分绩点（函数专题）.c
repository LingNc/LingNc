#include<stdio.h>
int GP(int grade){
    int Gp;
    Gp=(grade-50)/10;
    if(Gp<0) Gp=0;
    return Gp;
}
int main(){
    int n;
    double S_GP=0,S_point=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int point,grade;
        scanf("%d %d",&point,&grade);
        S_point+=point;
        S_GP+=point*GP(grade);
    }
    printf("%.1lf",S_GP/S_point);
    return 0;
}