#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#define endl '\n'
using namespace std;
void ringOne(char* str);
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    char s1[100001]={0},s2[100001]={0};
    cin>>s1>>s2;
    int len=strlen(s1);
    for(int i=1;i<=len;i++){
        if(strstr(s1,s2)!=NULL){
            puts("yes");
            return 0;
        }
        ringOne(s1);
    }
    puts("no");
    return 0;
}
void ringOne(char* str){
    string s=str;
    s.append(1,s[0]);
    s.erase(0,1);
    strcpy(str,&s[0]);
}