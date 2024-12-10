#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>
#define foe(i,a,b) for(int i=(a);i<=(b);i++)
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
    foe(i,0,a.size()-1){
        cout<<a[i];
        if(i!=a.size()-1) cout<<' ';
    }
    return 0;
}