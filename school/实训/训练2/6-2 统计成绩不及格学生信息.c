#include<stdio.h>
#define MAXN 100
struct student{
    long long id;
    char name[MAXN];
    int score[3];
};

#define string char
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
#include<stdlib.h>
void FailStudent(FILE *in,FILE *out){
    string str[1000]={ 0 };
    string *object[3]={
        "Math","English","C"
    };
    string id[13]={ 0 },name[12]={ 0 };
    int num;
    while(fgets(str,1000,in)){
        int obj[3];
        sscanf(str,"%s%s%d%d%d",id,name,obj,obj+1,obj+2);
        foe(i,0,2){
            if(obj[i]<60)
                fprintf(out,"%s %s %s\n",id,name,object[i]);
        }
    }
}

int main(){
    FILE *in,*out;

    in=fopen("in.txt","r");
    out=fopen("out.txt","w");

    if(in&&out){
        FailStudent(in,out);
    }
    else{
        puts("文件无法打开!");
    }

    if(in){
        fclose(in);
    }
    if(out){
        fclose(out);
        puts("文件保存成功!");
    }
    return 0;
}
/* 请在这里填写答案 */