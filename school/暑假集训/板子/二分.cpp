#include<bits/stdc++.h>
using i32=signed;
using i64=long long;
using namespace std;

//找到满足条件的第一个值,返回下标
//arr查找索引数组，val需要查找的值，check匹配函数（当前值，匹配值）
int half(vector<int> &arr,int val,bool check(int,int)){
    i64 mid,l=-1,r=arr.size();
    while(l+1<r){
        mid=l+r>>1;
        if(check(arr[mid],val)) r=mid;
        else l=mid;
    }
    return r;
}
//例如
//返回第一个大于等于val的值
bool check1(int num,int val){
    return num>=val;
}
//返回第一个大于val的值，即val的下一个值
bool check2(int num,int val){
    return num>val;
}