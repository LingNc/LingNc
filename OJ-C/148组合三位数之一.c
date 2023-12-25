#include<stdio.h>
#include<stdbool.h>

typedef struct m{
    int len;
    struct{
        char num[4];
    }word[22];
}three;

bool check(char num[]);
void del(three* word,int k);

int main(){
    int len=22;
    three word;
    word.len=len;
    for(int i=0;i<=21;i++)
        word.word[i].num[3]='\0';
    for(int i=10;i<=31;i++){
        int s=i*i;
        for(int j=2;j>=0;j--){
            word.word[i-10].num[j]=s%10+'0';
            s/=10;
        }
    }
    for(int i=0;i<=word.len-1;i++){
        if(check(word.word[i].num)!=true){
            del(&word,i);
            i--;
        }
    }
    int num[10]={0};
    //a
    for(int a=0;a<=word.len-1;a++){
        int A[10]={0};
        for(int i=0;i<=2;i++){
            int m=word.word[a].num[i]-'0';
            A[m]++;
            num[m]++;
        }

        //b
        for(int b=a+1;b<=word.len-1;b++){
            int flag=0;
            for(int i=0;i<=2;i++){
                if(num[word.word[b].num[i]-'0']>=1)
                    break;
                else{
                    //num[word.word[b].num[i]-'0']++;
                    flag++;
                }
            }

            //c
            if(flag==3){
                //save b
                int B[10]={0};
                for(int i=0;i<=2;i++){
                    int m=word.word[b].num[i]-'0';
                    B[m]++;
                    num[m]++;
                }
                for(int c=0;c<=word.len-1;c++){
                    if(c!=a&&c!=b){
                        int flag=0;
                        for(int i=0;i<=2;i++){
                            if(num[word.word[c].num[i]-'0']>=1)
                                break;
                            else{
                                flag++;
                            }
                        }
                        if(flag==3){
                            printf("%s %s %s",word.word[a].num,word.word[b].num,word.word[c].num);
                            return 0;
                        }
                    }
                }
                for(int i=0;i<=9;i++){
                    if(B[i])
                        num[i]--;
                }
            }
            for(int i=0;i<=9;i++){
                if(A[i])
                    num[i]--;
            }
        }
        return 0;
    }
}
bool check(char num[]){
    for(int i=0;i<=3;i++){
        if(num[i%3]==num[(i+1)%3])
            return false;
    }
    return true;
}

void del(three* word,int k){
    for(int i=k;i<=word->len-2;i++)
        word->word[i]=word->word[i+1];
    word->len--;
}