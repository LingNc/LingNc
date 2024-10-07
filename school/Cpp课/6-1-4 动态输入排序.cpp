/* 请在这里填写答案 */
//实现input函数
#include<iostream>

using namespace std;

void input(int *&a,int n){
    a=new int[n];
    for(int i=0;i<=n-1;i++) cin>>a[i];
}

void sort(int a[], int n){
    int i,j;
    for(i=0;i<n-1;i++){
        int min = i;
        for(j=i+1;j<n;j++){
            if(a[min]>a[j]) min = j;
        }
        int t = a[i]; a[i] = a[min]; a[min] = t;
    }
}

int main(){
    int *a;
    int n;
    cin>>n;                //输入数据的数量
    input(a,n);            //输入n个整数
    sort(a,n);            //将数组a按从小到大排序
    for(int i=0;i<n;i++)
        cout<<a[i]<<" "; //按顺序输出

    if(a!=NULL)
        delete []a;
    return 0;
}


