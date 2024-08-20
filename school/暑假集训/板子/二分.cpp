#include<bits/stdc++.h>
#include"A.cpp"

//找到满足条件的第一个值,没找到返回最大值
int bigger(vector<int> &str,int val){
    int l=-1,r=str.size();
    while(l+1<r){
        int mid=l+(r-l>>1);
        if(check()) r=mid;
        else l=mid;
    }
    // 没找到的判断条件
    return (r==str.size())?INF32:str[r];
}

//找到满足条件的最后一个值，没找到返回-1最小值
int lesser(vector<int> &str,int val){
    int l=-1,r=str.size();
    while(l+1<r){
        int mid=l+(r-l>>1);
        if(check()) l=mid;
        else r=mid;
    }
    // 记得加判断条件直接返回str[l]应该是l==-1返回-1
    return (l==-1)?-1:str[l];
}

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