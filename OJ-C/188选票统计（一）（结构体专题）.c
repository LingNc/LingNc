#include<stdio.h>
#include<string.h>
typedef struct{
    char name[6];
    int votes;
}people;
int main(){
    int n;
    people candidate[5]={{"zhang",0},{"wang",0},{"zhao",0},{"liu",0},{"miao",0}};
    scanf("%d",&n);
    //why?
    getchar();
    for(int x=1;x<=n;x++){
        char name[6]={'\0'};
        gets(name);
        for(int i=0;i<=4;i++){
            if(strcmp(candidate[i].name,name)==0)
                candidate[i].votes++;
        }
    }
    for(int i=0;i<=4;i++){
        printf("%s %d\n",candidate[i].name,candidate[i].votes);
    }
    return 0;
}