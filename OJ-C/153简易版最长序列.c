#include<stdio.h>
void sort(int list[],int n);
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        int num[n];
        int k=n-1;
        while(n--){
            scanf("%d",&num[n]);
        }
        sort(num,k);
        int flag=1,max=1;
        for(int i=0;i<=k-1;i++){
            if(num[i]==num[i+1]){
                flag++;
                if(flag>max)
                    max=flag;
            }
            else
                flag=1;
        }
        printf("%d\n",max);
    }
    return 0;
}
void sort(int list[],int n){
    for(int i=0;i<=n-1;i++){
        for(int j=0;j<=n-1;j++){
            if(list[j]>list[j+1]){
                int t=list[j];
                list[j]=list[j+1];
                list[j+1]=t;
            }
        }
    }
}