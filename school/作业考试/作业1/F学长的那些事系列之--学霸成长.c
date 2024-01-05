#include<stdio.h>
int main(){
    int nbr,avg;
    scanf("%d %d",&nbr,&avg);
    if(nbr>=300||avg<=50)
        printf("学霸");
    else if(nbr<100&&avg>500)
        printf("学渣");
    else
        printf("学酥");
    return 0;
}