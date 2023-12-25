#include<stdio.h>
void sort(int list[],int n);
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        int flag[11]={0};
        while(n--){
            int t;
            scanf("%d",&t);
            flag[t]++;
        }
        int max=flag[0];
        for(int i=1;i<=10;i++){
            if(flag[i]>max)
                max=flag[i];
        }
        printf("%d\n",max);
    }
    return 0;
}