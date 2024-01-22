#include<iostream>
#define ll long long
using namespace std;

double sum_fact(double n);
double factorial_ni(double n);
int main(){
    double res;
    puts("n e");
    puts("- -----------");
    for(int i=0;i<=9;i++){
        printf("%d %.9lf\n",i,sum_fact(i));
    }
    return 0;
}
double sum_fact(double n){
    double s=0;
    for(double i=0;i<=n;i+=1){
        s+=factorial_ni(i);
    }
    return s;
}
double factorial_ni(double n){
    double s=1;
    for(double i=1;i<=n;i+=1){
        s*=1/i;
    }
    return s;
}