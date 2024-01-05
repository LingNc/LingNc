#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    double prise[10]={0};
    double sum=0;
    for(int i=0;i<=n-1;i++){
        scanf("%lf",&prise[i]);
        sum+=prise[i];
    }
    double avg=sum/n;
    for(int i=0;i<=n-1;i++){
        if(prise[i]>avg) prise[i]*=0.9;
    }
    for(int i=0;i<=n-1;i++){
        printf("%.1lf",prise[i]);
        if(i<n-1) printf(" ");
    }
    printf("\n");
    return 0;
}