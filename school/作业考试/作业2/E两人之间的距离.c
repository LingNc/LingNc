#include<stdio.h>
#include<math.h>
double distance(int r,int va,int vb,int t);
int main(){
    int r,va,vb,t;
    while(scanf("%d %d %d %d",&r,&va,&vb,&t)!=EOF){
        printf("%.2lf\n",distance(r,va,vb,t));
    }
    return 0;
}
double distance(int r,int va,int vb,int t){
    double PI=3.14159;
    double C=2*PI*r;
    double s=(va+vb)*t;
    double int_s=s-(int)(s/C)*C;
    if(int_s<=PI*r)
        return int_s;
    else
        return 2*PI*r-int_s;
}
