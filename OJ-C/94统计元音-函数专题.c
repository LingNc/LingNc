#include<stdio.h>
int vowel(char ch){
    int flag=0;
    char vow[10] = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'U', 'u'};
    for (int i=0;i<=9;i++){
        if(ch==vow[i])
            flag += 1;
    }
    if(flag>=1) return 1;
    else
        return 0;
}
int main(){
    char ch;
    int flag = 0;
    while (1)
    {
        scanf("%c", &ch);
        if(ch=='\n') break;
        if (vowel(ch))
            flag += 1;
    }
    printf("%d", flag);
    return 0;
}