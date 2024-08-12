#include<bits/stdc++.h>
#include"A.cpp"

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
//找到满足条件的前一个值,返回下标
//arr查找索引数组，val需要查找的值，check匹配函数（当前值，匹配值）
int half_last(vector<int> &arr,int val,bool check(int,int)){
    i64 mid,l=-1,r=arr.size();
    while(l+1<r){
        mid=l+r>>1;
        if(check(arr[mid],val)) r=mid;
        else l=mid;
    }
    return l;
}
//例如
//返回第一个大于等于val的值
bool check1(const int &num,const int &val){
    return num>=val;
}
//返回第一个大于val的值，即val的下一个值
bool check2(const int &num,const int &val){
    return num>val;
}