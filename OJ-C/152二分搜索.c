#include<stdio.h>
int find(int num,int list[],int n);
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
    int a=0;
    int mid=(n-1)/2;
    for(int i=0;i<=mid+a;i++){
        if(list[i]==num)
            return i;
        if(i==mid+a&&i<=n-1)
            a+=(n-1-mid>=2)?(n-1-mid)/2:1;
    }
    return -1;
}