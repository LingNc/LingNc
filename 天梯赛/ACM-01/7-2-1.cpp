#include<cstdio>
#include<cstring>
using namespace std;
void move(char *str,int len);
int main(){
    char word[101]={0};
    int n;
    scanf("%[^\n]%*c",word);
    int len=strlen(word);
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