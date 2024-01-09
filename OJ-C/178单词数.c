#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int find_word(char* word[],char* str);
int main(){
    char* word[1000]={0};
    while(1){
        int i=0,num=0;
        while(1){
            word[i]=(char*)calloc(31,sizeof(char));
            char str[31]={0};
            scanf("%s",str);
            if(str[0]=='#') return 0;
            if(find_word(word,str)==0){
                strcpy(word[i],str);
                num++;
            }
            char ch=getchar();
            if(ch=='\n') break;
            if(i>1000) break;
        }
        printf("%d\n",num);
    }
    return 0;
}
int find_word(char* word[1000],char* str){
    char **ptr=word;
    while(*ptr!=NULL){
        if(strcmp(*ptr,str)==0)
            return 1;
        ptr++;
    }
    return 0;
}
