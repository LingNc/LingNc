#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
/* 赵逸飞 542307250130 */
int main(){
    string file_name;
    cout<<"请输入要加倍的文件名称: ";
    cin>>file_name;
    fstream source_file(file_name,ios::binary|ios::in|ios::out);
    if(!source_file.is_open()){
        cout<<"文件打开失败"<<endl;
        return 1;
    }
    source_file.seekg(0,ios::end);
    int file_len=source_file.tellg();
    source_file.seekg(0,ios::beg);
    vector<char> buffer(file_len);
    source_file.read(buffer.data(),file_len);
    source_file.write(buffer.data(),file_len);
    source_file.close();
    cout<<"文件加倍完成"<<endl;
    return 0;
}