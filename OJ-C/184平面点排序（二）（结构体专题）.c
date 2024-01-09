#include<stdio.h>
#include<stdlib.h>
typedef struct Point{
    int x,y;
}point;
int cmp(const void *a,const void *b){
    point *p1=(point*)a,*p2=(point*)b;
    int x=p1->x-p2->x;
    return (x!=0)?x:(p1->y-p2->y);
}
int main(){
    int n;
    scanf("%d",&n);
    point o[n];
    for(int i=0;i<=n-1;i++){
        scanf("%d%d",&o[i].x,&o[i].y);
    }
    qsort(o,n,sizeof(point),cmp);
    for(int i=0;i<=n-1;i++){
        printf("(%d,%d) ",o[i].x,o[i].y);
    }
    putchar('\n');
    for(int i=n-1;i>=0;i--){
        printf("(%d,%d) ",o[i].x,o[i].y);
    }
    putchar('\n');
    return 0;
}