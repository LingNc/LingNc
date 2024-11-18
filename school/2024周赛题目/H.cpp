#include<bits/stdc++.h>

using namespace std;


//利用双指针将串根据空格进行分割
vector <string> work(string str){
    vector<string> res;

    for(int i=0; i<str.size(); i++){
        int j=i; //i是字符
        string t="";
        //j = str.size() 或 str[j] = ' '
        while(j<str.size()&&str[j]!=' ')
            j++;
        t=str.substr(i,j-i);
        res.push_back(t);
        i=j;
    }
    return res;
}

int main(){
    string str;
    cin>>str;
    //将格式串是否带参存储起来
    unordered_map<string,int> have;
    for(int i=0; i<str.size(); i++){
        string t="-";
        t+=str[i];
        if(str[i]==':') continue;
        if((i<str.size()-1&&str[i+1]!=':')||i==str.size()-1)
            have[t]=1;
        else
            have[t]=2;
    }

    int n;
    cin>>n;
    getchar(); //读取行末回车

    for(int i=1; i<=n; i++){
        str="";
        //读取整一行字符串
        getline(cin,str);
        //将这行串根据空格进行拆分
        vector<string> txt=work(str);
        //使用map自动对键排序
        map<string,string> res; //<选项，参数>

        for(int j=1; j<txt.size(); j++){
            string x=txt[j];
            //这句话不能写，命令行的第一个单词可能并不是check。
            //if (x == "check") continue;
            if(have[x]==1)
                res[x]="*";
            else if(have[x]==2&&j<txt.size()-1)
                res[x]=txt[++j];
            else//这一句既不是合法的选项又不是某个选项的参数，停止分析
                break;
        }

        printf("Case %d:",i);
        for(auto x:res){
            cout<<" "<<x.first;
            if(x.second!="*")
                cout<<" "<<x.second;
        }
        cout<<endl;
    }
    return 0;
}