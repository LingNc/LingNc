#include<stdio.h>
#include<string.h>
int main(){
    int n,now,all=0,finish=0;
    scanf("%d %d%*c",&n,&now);
    int need[n];
    for(int i=0;i<=n-1;i++){
        need[i]=0;
    }
    char problem[n][501];
    for(int i=0;i<=n-1;i++){
        scanf("%[^\n]%*c",problem[i]);
        if(strstr(problem[i],"easy")==NULL&&strstr(problem[i],"qiandao")==NULL){
            all++;
            need[i]=1;
        }
    }
    for(int i=0;i<=now-1;i++){
        finish+=need[i];
    }
    int k=0,now_k;
    for(int i=0;i<=n-1;i++){
        if(need[i]==1){
            k++;
        }
        if(now==k){
            now_k=i;
            break;
        }
    }
    if(finish==all){
        printf("Wo AK le");
    }
    else{
        printf("%s",problem[now_k+1]);
    }
    return 0;
}