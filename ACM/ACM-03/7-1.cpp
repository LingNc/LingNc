#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
int main(){
    char word[101]={0};
    cin>>word;
    int len=strlen(word);
    int alpha[26]={0};
    for(int i=0;i<=len-1;i++){
        alpha[word[i]-'a']++;
    }
    int num=0;
    for(int i=0;i<=25;i++){
        if(alpha[i]!=0) num++;
    }
    if(num%2)
        puts("YI! WU!");
    else
        puts("CLEAN!");
    return 0;
}
