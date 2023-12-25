#include<stdio.h>

int getScore(char g){ 
    int flag=0;
    switch(g){
        case 'A':
            flag=95;
            break;
        case 'B':
            flag=85;
            break;
        case 'C':
            flag=75;
            break;
        case 'D':
            flag=65;
            break;
        default:
            flag=40;
            break;
    }
    return flag;
}

int main(){
    char ch;
    double S,n=0;
    while(1){
        scanf("%c",&ch);
        if(ch=='\n') break;
        S+=getScore(ch);
        n+=1;
    }
    printf("%.1lf",S/n);
    return 0;
}