#include<stdio.h>
#include<string.h>
int have_symmetry(char *str);
int is_reserve(char *str);
int main(){
    char str[10001]={0};
    scanf("%s",str);
    if(have_symmetry(str)&&is_reserve(str))
        puts("Yes");
    else
        puts("No");
        return 0;
}
int is_reserve(char *str){
    int len=strlen(str);
    int mid=(len-1)/2;
    for(int i=0,j=len-1;i<=mid,j>=mid;i++,j--){
        if(str[i]!=str[j]) return 0;
    }
    return 1;
}

int have_symmetry(char *str){
    int len=strlen(str);
    return (strspn(str,"AHIMOTUVWXY")==len)?1:0;
    
}