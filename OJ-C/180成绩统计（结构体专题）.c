#include<stdio.h>
#include<stdlib.h>

typedef struct student{
    char name[21];
    char ID[13];
    int chinese,math,english;
}stu;
int main(){
    int n;
    scanf("%d",&n);
    stu student[n];
    int max=0,k=0;
    for(int i=0;i<=n-1;i++){
        stu *p=&student[i];
        scanf("%s%s%*c%d%d%d",p->ID,p->name,
        &p->chinese,&p->math,&p->english);
        int sum=p->chinese+p->math+p->english;
        if(sum>max){
            max=sum;
            k=i;
        }
    }
    stu p=student[k];
    printf("%s %s %d %d %d\n",p.ID,p.name,p.chinese,p.math,p.english);
    return 0;
}