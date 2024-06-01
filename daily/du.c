#include <stdio.h>

struct StudentScore {
    char name[50];
    float scores[6];
    float average;
};
int main(){
    struct StudentScore student[61];
    int i;
    for(i=0;i<60;i++){
        scanf("%s",student[i].name);
        for(int j=0;j<6;j++){
            scanf("%f",&student[i].scores[j]);
        }
    }
    for(i=0;i<60;i++){
        float sum=0;
        for(int j=0;j<6;j++){
            sum+=student[i].scores[j];
        }
        float a=sum/6;
        student[i].average=a;
    }
    struct StudentScore temp;
    for(i=0;i<60;i++){
        for(int j=i+1;j<60;j++){
            if(student[i].scores<student[j].scores){
                temp=student[i];
                student[i]=student[j];
                student[j]=temp;
            }
        }
    }
    for(i=0;i<60;i++){
        printf("%s %.2f %.2f",student[i].name,student[i].scores,student[i].average);
    }
    return 0;
}
