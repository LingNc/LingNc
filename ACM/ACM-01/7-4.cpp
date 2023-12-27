#include<cstdio>
#include<cstring>

int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        int l1,l2;
        scanf("%d%d",&l1,&l2);
        getchar();
        char str1[l1+1],str2[l2+1];
        memset(str1,0,(l1+1)*sizeof(char));
        memset(str2,0,(l2+1)*sizeof(char));
        scanf("%s%*c",str1);
        scanf("%s%*c",str2);
        bool c1=check(str1,str1+l1),c2=check(str2,str2+l2);
        if(c1==false&&c2==false){
            puts("NO");
            return 0;
        }
        else if(c1==true){
            puts("YES");
            return 0;
        }
        else if(c1==false&&c2==true){
            char *p=str1;
            while(){
                
            }
        }
    }
    return 0;
}
bool check(char* start,char* end){
    char *p=start;
    while(p!=end){
        if(*p==*(p+1))
            return false;
        p++;
    }
    return true;
}