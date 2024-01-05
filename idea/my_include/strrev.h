#include<string.h>
char *strrev(char *str){
    char *right = str,*left = str;
    char ch;
    while(*right)
        right++;
    right--;
    while(left<right){
        ch=*left;
        *left++=*right;
        *right--=ch;
    }
    return str;
}
char* strrev(char *str){
    int len=strlen(str);
    for(int i=0;i<=(len-1)/2;i++){
        char t=str[i];
        str[i]=str[len-1-i];
        str[len-1-i]=t;
    }
    return str;
}