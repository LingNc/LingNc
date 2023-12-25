#include<iostream>
using namespace std;

int compare_num(char ch1,char ch2);
int main(){
    char ch1,ch2;
    cin>>ch1>>ch2;
    cin.get();
    cout<<compare_num(ch1,ch2);
    return 0;
}
int compare_num(char ch1,char ch2){
    double a=(ch1>='a'&&ch1<='z')?ch1-'a'+'A'+0.5:ch1;
    double b=(ch2>='a'&&ch2<='z')?ch2-'a'+'A'+0.5:ch2;
    if(a>b)
        return 1;
    else if(a<b)
        return -1;
    else
        return 0;
}