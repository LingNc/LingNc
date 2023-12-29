#include<cstdio>
#include<cstring>
#include<string>

using namespace std;

bool check(char* start,char* end);
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
            continue;
        }
        else if(c1==true){
            puts("YES");
            continue;
        }
        else if(c1==false&&c2==true){
            char *p=str1;
            char *check_ptr=str1;
            char *end=str1+l1;
            string s1=str1;
            char s2[]={str2[0],'\0',str2[l2-1]};
            bool flag;
            while(p!=end-1){
                flag=0;
                if(*p==*(p+1)){
                    int i=p-str1;
                    s1.insert(i+1,1,str2[0]);
                    s1.insert(i+2,1,'\0');
                    s1.insert(i+3,1,str2[l2-1]);
                }
                flag=check(check_ptr,p+1);
                if(flag==0) break;
                check_ptr=p+3;
                p++;
            }
            if(flag)
                puts("YES");
            else
                puts("NO");
        }
    }
    return 0;
}
bool check(char* start,char* end){
    char *p=start;
    while(p!=end-1){
        if(*p==*(p+1))
            return false;
        p++;
    }
    return true;
}