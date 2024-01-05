#include<stdio.h>
void in();
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        in();
    }
    return 0;
}
void in(){
    int x1,y1,x2,y2;
    scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
    int x,y;
    scanf("%d %d",&x,&y);
    if(x>=x1&&x<=x2&&y>=y1&&y<=y2){
        puts("YES");
    }
    else
        puts("NO");
}