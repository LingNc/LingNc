#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>
#define endl '\n'
#define foe(i,a,b) for(auto i=(a);i<=(b);i++)
using namespace std;
void yes(fstream &f){
    if(f) cout<<"文件打开成功"<<endl;
    else{
        cout<<"文件打开失败"<<endl;
        exit(1);
    }
}
int main(){
    fstream in("in.txt",ios::in);
    // yes(in);yes(out);
    string str;
    bool isSecret=false;
    while(!in.eof()){
        getline(in,str);
        if(str.find("secret",0)!=str.npos){
            cout<<str<<endl;
            isSecret=true;
        }
    }
    if(!isSecret) cout<<"No secret"<<endl;
    in.close();
    return 0;
}