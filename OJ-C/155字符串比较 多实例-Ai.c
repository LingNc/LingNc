#include <stdio.h>
#include <string.h>

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        char str1[10000],str2[10000];
        scanf("%s",str1);
        scanf("%s",str2);
        int len1=strlen(str1);
        int len2=strlen(str2);
        int i=0,j=0;
        while(i<len1&&j<len2){
            if(str1[i]<str2[j]){
                printf("YES\n");
                break;
            }
            else if(str1[i]>str2[j]){
                printf("NO\n");
                break;
            }
            else{
                i++;
                j++;
            }
        }
        if(i==len1&&j==len2){
            printf("NO\n");
        }
    }
    return 0;
}