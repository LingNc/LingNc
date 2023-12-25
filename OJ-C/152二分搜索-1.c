#include<stdio.h>
int _f5=0;
int IF=0;
int main(){
    int n;
    scanf("%d",&n);
    int num[n];
    for(int i=0;i<=n-1;i++)
        scanf("%d",&num[i]);
    int m;
    scanf("%d",&m);
    while(m--){
        int a;
        scanf("%d",&a);
        int flag=find(a,num,n);
        if(flag==-1)
            printf("Not found!\n");
        else
            printf("%d\n",flag);
    }
    return 0;
}
int find(int num,int list[],int n){
    int start=0,end=n-1;
    int i=0;
    while(start<=end){
        int mid=(start+end)/2;
        if(list[mid]==num)
            return mid;
        else if(list[mid]<num)
            start=mid+1;
        else if(list[mid]>num)
            end=mid-1;
    }
    return -1;
}

