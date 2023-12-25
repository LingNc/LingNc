#include<stdio.h>
int main(){
    int i,n,fuhao=1;
    double y=0.0,xiang=1,x;
    scanf("%d",&x);
    for(i=1;i<=10;i++){
        double fenzi=1.0,fenmu=1.0;
        if(i%2==1)
            fuhao=1;
        else
            fuhao=-1;
        for(n=1;n<=xiang;n++){
            fenzi*=x;
        }
        for(n=1;n<=xiang;n++){
            fenmu*=n;
        }
        xiang=xiang+2;
        y=y+fuhao*fenzi/fenmu;
    }
    printf("%.3lf",y);

    return 0;
}