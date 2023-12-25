#include<stdio.h>
#include<string.h>
int compare(char* p,int num);
int main(){
    char list[1001]={0};
    scanf("%s",list);
    int n;
    scanf("%d",&n);
    int len=strlen(list);
    int num=0;
    for(int i=0;i<=len-2;i++){
        if(compare(&list[i],n)){
            num++;
        }
    }
    printf("%d",num);
    return 0;
}
int compare(char* p,int num){
    for(int i=0;i<=num-2;i++){
        if(p[i]==p[i+1]&&p[i]=='1'){
            continue;
        }
        else{
            return 0;
        }
    }
    return 1;
}