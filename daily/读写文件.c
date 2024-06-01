#include<stdio.h>
#include<string.h>
typedef struct student{
    char name[20];
    int id;
    double score[6];
    double svg_score;
}stu;

int main(){
    //结构体实例化
    stu S[61];
    //打开文件
    FILE *fp=fopen("test.txt","w");
    for(int i=1;i<=4;i++){
        scanf("%d%s",&S[i].id,S[i].name);
        for(int j=0;j<=5;j++){
            scanf("%lf",&S[i].score[j]);
        }
    }
    //计算平均值
    for(int i=1;i<=4;i++){
        double sum=0;
        for(int j=0;j<=5;j++){
            sum+=S[i].score[j];
        }
        S[i].svg_score=sum/6;
    }
    //把信息输出到控制台
    for(int i=1;i<=4;i++){
        printf("%d %s %.2lf ",S[i].id,S[i].name,S[i].svg_score);
        for(int j=0;j<=5;j++){
            printf("%.2lf ",S[i].score[j]);
        }
    }
    //把信息输出到文件
    for(int i=1;i<=4;i++){
        fprintf(fp,"%d %s %.2lf ",S[i].id,S[i].name,S[i].svg_score);
        for(int j=0;j<=5;j++){
            fprintf(fp,"%.2lf ",S[i].score[j]);
        }
        fprintf(fp,"\n");
    }

    memset(S,0,sizeof(S));
    //读入60个学生成绩
    for(int i=1;i<=60;i++){
        scanf("%d%s",&S[i].id,S[i].name);
        for(int j=0;j<=5;j++){
            scanf("%lf",&S[i].score[j]);
        }
    }
    //计算平均值
    for(int i=1;i<=60;i++){
        for(int j=0;j<=5;j++){
            S[i].svg_score+=S[i].score[j];
        }
        S[i].svg_score/=6;
    }
    //冒泡排序按照六个成绩平均值
    for(int i=1;i<=60;i++){
        for(int j=i+1;j<=60;j++){
            if(S[i].svg_score<S[j].svg_score){
                stu temp=S[i];
                S[i]=S[j];
                S[j]=temp;
            }
        }
    }
    //按照名次输出为 rank id name svg 1 2 3 4 5 6
    for(int i=1;i<=60;i++){
        printf("%d %d %s %.2lf %.2lf %.2lf %.2lf %.2lf %.2lf %.2lf\n",i,S[i].id,S[i].name,S[i].svg_score,S[i].score[1],S[i].score[2],S[i].score[3],S[i].score[4],S[i].score[5],S[i].score[6]);
    }
    return 0;
}