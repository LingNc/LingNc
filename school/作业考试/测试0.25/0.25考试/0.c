#include <stdio.h>
#include <math.h>
typedef struct point point;
struct point{
    int x,y;//x是点的横坐标,y是点的纵坐标 
};
double dist(point A,point B) ;
int main(){
    point A,B;
    double dis;
    scanf("%d%d%d%d",&A.x ,&A.y ,&B.x,&B.y);
    dis=dist(A,B);
    printf("%.2f\n",dis) ;
    return 0;
}

double dist(point A,point B){
    double dis;
    dis=sqrt((B.x-A.x)*(B.x-A.x)+(B.y-A.y)*(B.y-A.y));
    return dis;
}