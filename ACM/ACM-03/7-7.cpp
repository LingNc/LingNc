#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
using namespace std;
void del(char *str,int k,int n);
int check(char* str,char* result);
int main(){
    double a=0,b=0,c=0,d=0;
    char str[1001]={0};
    scanf("%[^\n]%*c",str);
    int len=strlen(str);
    for(int i=0;i<=len-1;i++){
        if(str[i]==' '){
            del(str,i,1000);
            i--;
            len--;
        }
    }
    string s1=str;
    s1.insert(s1.length(),1,'+');
    s1.insert(0,1,'+');
    s1.replace(s1.find('='),1,1,'+');
    for(int i=0;i<=s1.length()-2;i++){
        if(s1[i]=='+'&&s1[i+1]=='x'){
            s1.insert(i+1,1,'1');
            i++;
        }
        if(s1[i]!='+'&&s1[i+1]=='-'){
            s1.insert(i+1,1,'+');
            i++;
        }
    }
    memset(str,0,1001*sizeof(char));
    len=s1.length();
    for(int i=0;i<=len-1;i++){
        str[i]=s1[i];
        if(str[i]=='+'){
            str[i]='\0';
        }
    }
    str[len]=0;
    del(str,0,1000);
    char num[100]={0};
    for(int i=1;i<=3;i++){
        int flag=check(str,num);
        if(flag==1)
            sscanf(num,"%lf",&a);
        else if(flag==2)
            sscanf(num,"%lf",&b);
        else if(flag==3)
            sscanf(num,"%lf",&c);
        memset(num,0,sizeof(num));
    }
    check(str,num);
    sscanf(num,"%lf",&d);
    c=c-d;
    double delta=sqrt(b*b-4*a*c);
    double r_1=(-b+delta)/(2*a),r_2=(-b-delta)/(2*a);
    printf("%.6lf %.6lf\n",r_1,r_2);
    return 0;
}
int check(char* str,char* result){
    int len=strlen(str);
    int flag=0;
    if(str[len-1]=='x'){
        flag=2;
    }
    else if(str[len-2]=='^'){
        flag=1;
    }
    else if(str[len-1]>='0'&&str[len-1]<='9'){
        flag=3;
    }
    strcat(result,str);
    for(int i=0;i<=len;i++){
        del(str,0,1000);
    }
    return flag;
}
void del(char *str,int k,int n){
    for(int i=k;i<=n;i++){
        str[i]=str[i+1];
    }
}
//+a x^2+b x+c+=+d+