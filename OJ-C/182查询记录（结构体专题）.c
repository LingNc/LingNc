#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student{
    char name[21];
    char ID[13];
    int chinese,math,english;
}stu;
int main(){
    int n;
    scanf("%d",&n);
    stu student[n];
    for(int i=0;i<=n-1;i++){
        stu *p=&student[i];
        scanf("%s%s%*c%d%d%d",p->ID,p->name,
        &p->chinese,&p->math,&p->english);
    }
    char ID[13]={0};
    scanf("%s",ID);
    for(int i=0;i<=n-1;i++){
        if(strcmp(student[i].ID,ID)==0){
            stu p=student[i];
            printf("%s %s %d %d %d\n",p.ID,p.name,p.chinese,p.math,p.english);
            return 0;
        }
    }
    puts("Not Found");
    return 0;
}