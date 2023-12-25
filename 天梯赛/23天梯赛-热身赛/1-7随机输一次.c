#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct win{
    bool flag;
    struct win *next;
}Linkwin;
Linkwin *create(int n);

int main(){
    int N;
    scanf("%d",&N);
    int K[N];
    memset(K,0,sizeof(K));
    int sum=N;
    for(int i=0;i<=N-1;i++){
        scanf("%d",&K[i]);
        sum+=K[i];
    }
    getchar();
    Linkwin *win=create(sum);
    for(int i=0;i<=N-1;i++){
        while(K[i]--){
            win->flag=1;
            win=win->next;
        }
        win->flag=0;
        win=win->next;
    }
    char* game[3]={"JianDao","ChuiZi","Bu"};
    char name[8]={0};
    while(scanf("%[^\n]%*c",&name)!=EOF){
        for(int i=0;i<=2;i++){
            if(strcmp(game[i],name)==0){
                if(win->flag)
                    printf("%s\n",game[(i+1)%3]);
                else
                    printf("%s\n",game[(i-1+3)%3]);
                win=win->next;
                break;
            }
        }
    }
    return 0;
}

Linkwin *create(int n){
    Linkwin *head,*node,*end;
    end=head=(Linkwin *)malloc(sizeof(Linkwin));
    for(int i=1;i<=n-1;i++){
        node=(Linkwin *)malloc(sizeof(Linkwin));
        end->next=node;
        end=node;
    }
    end->next=head;
    return head;
}