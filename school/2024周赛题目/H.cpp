#include <iostream>
#include <unordered_map>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

unordered_map <string,int> m; // <-a, 1/2>

vector <string> work(string str) //利用双指针将串根据空格进行分割
{
    vector <string> res;
    res.clear();

    for(int i=0; i<str.size(); i++){
        int j=i; //i是字符
        string t="";
        while(j<str.size()&&str[j]!=' ') j++; //j = str.size() 或 str[j] = ' '
        t=str.substr(i,j-i);
        res.push_back(t);
        //cout << t << " ";
        i=j;
    }
    return res;
}

int main(){
    string str;
    cin>>str;

    for(int i=0; i<str.size(); i++) //将格式串是否带参存储起来
    {
        string t="-";
        t+=str[i];
        if(str[i]==':') continue;
        if((i<str.size()-1&&str[i+1]!=':')||i==str.size()-1)  m[t]=1;
        else m[t]=2;
        //cout << str[i] << " " << m[str[i]] << endl;
    }

    int n;
    cin>>n;

    getchar(); //读取回车
    for(int i=1; i<=n; i++){
        str="";
        getline(cin,str); //读取整一行字符串
        //cout << str << endl;

        vector <string> txt;
        txt.clear();
        txt=work(str);//将这行串根据空格进行拆分

        unordered_map <string,string> res; //<选项，参数》
        res.clear();

        for(int j=1; j<txt.size(); j++){
            string x=txt[j];
            //if (x == "ls") continue; //这句话千万不能写，命令行的第一个单词可能并不是ls。。写了就0分。。
            if(m[x]==1){
                res[x]="*";
            }
            else if(m[x]==2&&j<txt.size()-1){
                res[x]=txt[++j];
            }
            else break;
        }

        unordered_map <string,int> f;
        f.clear();

        sort(txt.begin(),txt.end());
        printf("Case %d:",i);
        for(auto x:txt){
            if(res[x]!=""&&f[x]==0){
                f[x]=1;
                cout<<" "<<x;
                if(res[x]!="*") cout<<" "<<res[x];
            }
        }
        cout<<endl;
    }
    return 0;
}