#include<stdio.h>
#include<stdlib.h>
typedef struct Point{
    int x,y;
}point;
int distance(point* o);
int cmp(const void *a,const void *b){
    point *p1=(point*)a,*p2=(point*)b;
    return distance(p1)-distance(p2);
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
    return 0;
}
int distance(point* o){
    return o->x*o->x+o->y*o->y;
}