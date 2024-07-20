#include<stdio.h>
#include<math.h>
int main(){
    double a,b,c;
    while(1){
        if(scanf("%lf%lf%lf",&a,&b,&c)==EOF)
            break;
        double delta=sqrt(b*b-4*a*c);

        printf("%.2lf %.2lf",(-b+delta)/(2*a),(-b-delta)/(2*a));
    }

    return 0;
}

