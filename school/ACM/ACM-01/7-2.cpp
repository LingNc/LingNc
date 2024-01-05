#include<cstdio>
#include<cstring>
using namespace std;
void move(char *str,int len);
int main(){
    char word[10+1]={0};
    int n;
    fgets(word,10+2,stdin);
    int len=strlen(word)-1;
    word[len]='\0';
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        move(word,len);
    }
    printf("%s",word);
    return 0;
}
void move(char *str,int len){
    char t=str[0];
    for(int i=0;i<=len-1;i++){
        str[i]=str[i+1];
    }
    str[len-1]=t;
}