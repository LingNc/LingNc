#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

int main(){
    string str;
    getline(cin,str);
    vector<int> a;
    string temp;
    for(char c:str){
        if(isdigit(c)){
            temp+=c;
        }
        else{
            if(!temp.empty()){
                a.push_back(stoi(temp));
                temp="";
            }
        }
    }
    if(!temp.empty()){
        a.push_back(stoi(temp));
    }
    cout<<a.size()<<endl;
    for(int i=0; i<a.size(); i++){
        cout<<a[i];
        if(i!=a.size()-1) cout<<' ';
    }
    return 0;
}