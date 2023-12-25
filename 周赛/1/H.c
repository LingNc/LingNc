#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);

    int health=10,exp=0,level=0; // 当前等级

    for(int i=1;i<=n;i++){
        int x,exp_add;
        scanf("%d %d",&x,&exp_add);

        health-=x;
        if(health>=10)
            health=10;
        if(health<=0)
            break;

        exp+=exp_add;
    }
    int j=1;
    while(1){
        if(exp>=j){
            exp-=j;
            j*=2;
            level++;
        }
        else
            break;
    }

    printf("%d %d",level,exp);
    return 0;
}
