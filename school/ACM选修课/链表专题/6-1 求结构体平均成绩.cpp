#include <stdio.h>
#define N 20
typedef struct
{
    char no[10];
    double score;
}RECORD;

double avg(RECORD x[],int n);

int main()
{
    RECORD a[N];
    int n,i;
    double av;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%s%lf",a[i].no,&a[i].score);
    av=avg(a,n);
    printf("%f",av);
    return 0;
}

double avg(RECORD x[],int n){
    double avg_num=0;
    for(int i=0;i<=n-1;i++){
        avg_num+=x[i].score;
    }
    return avg_num/n;
}