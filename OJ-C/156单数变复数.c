#include<stdio.h>
#include<string.h>
void plural(char *str);
int main(){
    char word[21]={0};
    scanf("%s",word);
    plural(word);
    puts(word);
    return 0;
}
void plural(char *str){
    int len=strlen(str);
    char end[2]={0};
    for(int i=len-2;i<=len-1;i++){
        end[i-len+2]=str[i];
    }
    if(end[1]=='y'){
        str[len-1]='i';
        strcat(str,"es");
    }
    else if(end[1]=='s'||end[1]=='x'||strcmp(end,"ch")==0||strcmp(end,"sh")==0){
        strcat(str,"es");
    }
    else if(end[1]=='o'){
        strcat(str,"es");
    }
    else{
        strcat(str,"s");
    }
}