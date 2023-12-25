#include<stdio.h>
int common(int x,int y);
int main(){
    int x,y;
    scanf("%d %d",&x,&y);
    printf("%d",common(x,y));
    return 0;
}
int common(int x,int y){
    if(x==y)
        return x;
    else if(x>y)
        return common(x/2,y);
    else
        return common(x,y/2);
}