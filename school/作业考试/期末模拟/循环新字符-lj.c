#include <stdio.h>
#include <ctype.h>
#include <string.h>
char encryptChar(char ch,int x){
    if(isalpha(ch)){
        char base=isupper(ch)?'A':'a';
        return (ch-base+x+1)%26+base;
    }
    return ch;
}

int main(){
    int n;
    scanf("%d",&n);
    getchar();

    for(int i=0; i<n; i++){
        char input[1001]={0};
        fgets(input,sizeof(input),stdin);
        int alpha[127]={0},alpha_k[127]={0};
        int len=strlen(input);
        int k=0;
        for(int j=0;j<len;j++){
            char ch=input[j];
            char op;
            if(alpha[ch]==0){
                op=encryptChar(ch,k);
                alpha[ch]++;
                alpha_k[ch]=k;
                k++;
            }
            else{
                op=encryptChar(ch,alpha_k[ch]);
            }
            printf("%c",op);
        }
    }
    return 0;
}