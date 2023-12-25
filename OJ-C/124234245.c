#include<stdio.h>
#include<time.h>
int main(){
    clock_t start_time,end_time;
    start_time=clock();//获取开始执行时间

    //过程main
#include<stdio.h>
    int main(){
        int len=21;
        char num[22][4]={'\0'};
        for(int i=10;i<=31;i++){
            int s=i*i;
            for(int j=2;j>=0;j--){
                num[i-10][j]=s%10+'0';
                s/=10;
            }
        }
        for(int i=0;i<=len;i++){
            int n[10]={0};
            int flag=1;
            for(int j=0;j<=2;j++){
                if(n[num[i][j]-'0']!=0){
                    flag=0;
                    break;
                }
                else{
                    n[num[i][j]-'0']++;
                    continue;
                }
            }
            if(flag==0){
                for(int j=i;j<=len-1;j++){
                    for(int m=0;m<=2;m++)
                        num[j][m]=num[j+1][m];
                }
                len--;
                i--;
            }
        }
        char all[286][9]={'\0'};
        int m=0;
        for(int i=0;i<=len-2;i++){
            for(int j=i+1;j<=len-1;j++){
                for(int k=j+1;k<=len;k++){
                    int a=0;
                    for(int n=0;n<=2;n++){
                        all[m][a]=num[i][n];
                        a++;
                    }
                    for(int n=0;n<=2;n++){
                        all[m][a]=num[j][n];
                        a++;
                    }
                    for(int n=0;n<=2;n++){
                        all[m][a]=num[k][n];
                        a++;
                    }
                    m++;
                    //printf("%s%s%s ",num[i],num[j],num[k]);
                }

            }
        }

        int all_len=m,l=0;
        for(int i=0;i<=all_len;){
            int n[10]={0};
            int flag=1;
            for(int j=0;j<=8;j++){
                if(n[all[i][j]-'0']!=0){
                    flag=0;
                    break;
                }
                else{
                    n[all[i][j]-'0']++;
                    continue;
                }
            }
            if(flag==0){
                for(int j=i;j<=all_len-2;j++){
                    for(int m=0;m<=9;m++)
                        all[j][m]=all[j+1][m];
                }
                all_len--;
            }
            else{
                l++;
                i++;
            }
        }
        for(int j=0;j<=l-1;j++){
            for(int i=0;i<=8;i++){
                printf("%c",all[j][i]);
                if(i%3==2) printf(" ");
            }
        }
        printf("\b");
    }

    main();
    end_time=clock();//获取结束时间
    double Times=(double)(end_time-start_time)/CLOCKS_PER_SEC;
    printf("\nThis time: %.3lfms",Times*1000);

    return 0;
}