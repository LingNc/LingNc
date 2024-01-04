#include<stdio.h>
#include<string.h>
void reverse(char* str);
int main(){
    char str[101]={0};
    scanf("%s",str);
    reverse(str);
    puts(str);
    return 0;
}
//函数求出str的逆转数并存入str
void reverse(char* str){
    if(str[0]=='-')
        reverse(str+1);
    else{
        int len=strlen(str);
        char* ptr=&str[len-1];
        if(str[len-1]=='0')
            while(ptr!=str){
                if(*ptr=='0'&&*(ptr-1)!='0'){
                    ptr--;
                    break;
                }
                ptr--;
            }
        len=ptr-str;
        for(int i=0;i<=len/2;i++){
            char t=str[i];
            str[i]=str[len-i];
            str[len-i]=t;
        }
    }
}