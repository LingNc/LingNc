#include <bits/stdc++.h>
using i64=long long;

class BigInt{
    int *_data;
    int maxn;
    int len;
    BigInt(int maxn):maxn(maxn),_data(new int[maxn]){}
    void init(i64 num){
        int k=0;
        while(num){
            _data[k++]=num%10;
            num/=10;
        }
        len=k;
    }
    void init(std::string num){
        len=num.size();
        for(int i=len-1;i>=0;--i) _data[len-i]=num[i]-'0';
    }
    void flatten(int Len){
        len=Len;
        for(int i=1;i<=len;++i){
            _data[i+1]+=_data[i]/10;
            _data[i]%=10;
        }
        while(!_data[len])
            len--;
    }
    int &operator[](int index){
        return _data[index];
    }
    friend BigInt operator+(BigInt &a,BigInt &b);
    friend BigInt operator*(BigInt &a,BigInt &b);
};
BigInt operator+(BigInt &a,BigInt &b){
    BigInt res(a.maxn);
    int len=std::max(a.len,b.len);
    for(int i=1;i<=len;++i){
        res[i]=a[i]+b[i];
    }
    // 处理进位
    res.flatten(len+1);
    return res;
}
BigInt operator*(BigInt &a,BigInt &b){
    BigInt res(a.maxn);
    for(int i=1;i<=a.len;++i){
        for(int j=1;j<=b.len;++i){
            res[i+j-1]+=res[i]*res[j];
        }
    }
    // 处理进位
    res.flatten(a.len+b.len);
    return res;
}