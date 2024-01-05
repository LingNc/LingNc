#include<stdio.h>
#include<string.h>
int main(){
    int n;
    scanf("%d",&n);
    char name[n][21];
    int grade[n];
    int list[n];
    for(int i=0;i<=n-1;i++){
        for(int j=0;j<=20;j++){
            name[i][j]=0;
        }
        scanf("%s %d",name[i],&grade[i]);
        list[i]=i;
    }
    //sort
    for(int j=0;j<=n-2;j++){
        for(int i=0;i<=n-2;i++){
            if(grade[list[i+1]]>grade[list[i]]){
                int t=list[i];
                list[i]=list[i+1];
                list[i+1]=t;
            }
        }
    }
    /*
    for(int j=0;j<=n-2;j++){
    for(int i=0;i<=n-2;i++){
        int len1=strlen(name[list[i]]);
        int len2=strlen(name[list[i+1]]);
        if(grade[list[i]]==grade[list[i+1]]&&len1<len2){
            int t=list[i];
            list[i]=list[i+1];
            list[i+1]=t;
        }
    }
    }
    */
    for(int j=0;j<=n-2;j++){
        for(int i=0;i<=n-2;i++){
            if(grade[list[i]]==grade[list[i+1]]&&name[list[i]][0]>name[list[i+1]][0]){
                int t=list[i];
                list[i]=list[i+1];
                list[i+1]=t;
            }
        }
    }
    for(int i=0;i<=n-1;i++){
        printf("%s %d",name[list[i]],grade[list[i]]);
        if(i<n-1) printf("\n");
    }
    
    return 0;
}