#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void sum_price();
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        sum_price();
    }
    return 0;
}
double price(char* str){
    int len=strlen(str);
    char* ptr=NULL;
    for(int i=len-1;i>=0;i--){
        if(str[i]==' '){
            ptr=&str[i];
            break;
        }
    }
    return atof(ptr);
}
void sum_price(){
    int n;
    scanf("%d",&n);
    getchar();
    double sum=0;
    while(n--){
        char str[201]={0};
        scanf("%[^\n]%*c",str);
        sum+=price(str);
    }
    printf("%.1lf\n",sum);
}