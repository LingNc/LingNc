#define 导入 include
#define 输入输出 iostream
#define 使用 using
#define 命名空间 namespace
#define 标准空间 std
#define 是否 bool
#define 整数 int
#define 如果 if
#define 返回 return
#define 真 true
#define 假 false
#define 主函数 main
#define 输入 cin
#define 输出 cout
#define 结束 endl
#define ； ;
#define （ (
#define （ )

#导入 <输入输出>
使用 命名空间 标准空间;

是否 判断偶数（）{
    整数 数；
    如果 （数%2==0）{
        返回 真；
}
返回 数；
}

整数 主函数（）{
    整数 数字；
    输出<<"输入一个数字："；
    输如>>数字；

    输出<<判断偶数（ 数字 ）<<结束；

    返回 假；
}
// #include<iostream>
// using namespace std;

// bool odd(int x){
//     if(x%2==0){
//         return true;
//     }
//     return false;
// }
// int main(){
//     int num;
//     cout<<"输入一个数字：";
//     cin>>num;

//     cout<<odd(num)<<endl;

//     return 0;
// }
