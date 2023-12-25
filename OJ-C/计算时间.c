#include<time.h>
void main(){
    clock_t start_time,end_time;
    start_time=clock();

    end_time=clock();
    double Times=(double)(end_time-start_time)/CLOCKS_PER_SEC;
    printf("%f seconds\n",Times);
}