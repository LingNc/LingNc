#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#define endl '\n'
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;

int main(){
    char str[300]={ 0 };
    char *a[200]={ NULL };
    cin.getline(str,300,'\n');
    int len=strlen(str);
    bool flag=0;
    int next=0;
    foe(i,0,len-1){
        if(!flag){
            if(isdigit(str[i])){
                flag=1;
                a[next++]=str+i;
            }
        }
        else{
            if(!isdigit(str[i])){
                flag=0;
                str[i]=0;
            }
        }
    }
    cout<<next<<endl;
    foe(i,0,next-1){
        cout<<stoi(a[i]);
        if(i!=next-1) cout<<' ';
    }
    return 0;
}