#include<iostream>
#include<fstream>
using namespace std;


int main(int argc,char *argv[]){
    string source_name=argv[1];
    string dest_name=argv[2];
    fstream source_file(source_name,ios::in);
    if(!source_file.is_open())
        cout<<"error: 文件打开失败或指定文件不存在"<<endl;
    fstream dest_file(dest_name,ios::out);
    if(!dest_file.is_open())
        cout<<"文件打开失败"<<endl;

    string str;
    int flag=0;
    while(getline(source_file,str)){
        // cout<<str.size()<<endl;
        if(str.size()==0)
            continue;
        int str_len=0,is=0;
        for(int i=0;i<=str.size()-1;i++){
            auto it=str[i];
            if(it=='{'||it=='}'){
                if(!flag) dest_file.put(it),str_len++;
                if(it=='{') flag++;
                else flag--;
            }
            if(i+1<str.size()&&(str.substr(i,2)=="/*"||str.substr(i,2)=="*/")){
                if(str.substr(i,2)=="/*") flag++;
                else flag--;
                if(!flag){
                    i++;continue;
                }
            }
            if(i+1<str.size()&&str.substr(i,2)=="//"){
                i++;
                is=1;
            }
            if(!flag&&!is) dest_file.put(it),str_len++;
        }
        if(str_len) dest_file<<'\n';
        is=0;
    }
    source_file.close();
    dest_file.close();
    return 0;
}