#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student{
    char name[21];
    char ID[13];
    int chinese,math,english;
}stu;
int cmp(const void *a,const void *b){
    stu *p1=(stu*)a,*p2=(stu*)b;
    return strcmp(p1->ID,p2->ID);
}
int main(){
    int n;
    scanf("%d",&n);
    stu student[n+1];
    for(int i=0;i<=n-1;i++){
        stu *p=&student[i];
        scanf("%s%s%*c%d%d%d",p->ID,p->name,
        &p->chinese,&p->math,&p->english);
    }

    stu *p=&student[n];
    scanf("%s%s%*c%d%d%d",p->ID,p->name,&p->chinese,&p->math,&p->english);
    for(int i=0;i<=n-1;i++){
        if(strcmp(student[i].ID,p->ID)==0){
            puts("error!");
            return 0;
        }
    }
    qsort(student,n+1,sizeof(stu),cmp);
    for(int i=0;i<=n;i++){
        stu p=student[i];
        printf("%s %s %d %d %d\n",p.ID,p.name,p.chinese,p.math,p.english);
    }
    return 0;
}