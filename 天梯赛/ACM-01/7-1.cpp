#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<climits>
#include<string>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        int A,B,C;
        scanf("%d %d %d",&A,&B,&C);
        getchar();
        if(C==A*B){
            puts("Lv Yan");
        }
        else if(C==A+B){
            puts("Tu Dou");
        }
        else{
            puts("zhe du shi sha ya!");
        }
    }
    return 0;
}