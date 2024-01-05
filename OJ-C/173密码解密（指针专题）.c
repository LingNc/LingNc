#include<stdio.h>
#include<string.h>

void decrypt(char* cipher,char* plain);
int main(){
    char cipher[201]={0},plain[201]={0};
    scanf("%s",cipher);
    decrypt(cipher,plain);
    puts(plain);
    return 0;
}
//将密文cipher解密后将明文存入plain
void decrypt(char* cipher,char* plain){
    int len=strlen(cipher)/2;
    for(int i=0;i<=len-1;i++){
        plain[i]=10*(cipher[2*i]-'0')+cipher[2*i+1]-'0'+24;
    }
}