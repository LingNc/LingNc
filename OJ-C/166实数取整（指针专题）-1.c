#include <stdio.h>
#include <string.h>

char* rounding(char* p);

int main(void){
    char ch[1000]={0};

    gets(ch);

    char* flag=rounding(ch);

    if(flag==NULL)
        printf("0\n");
    else
        printf("%s\n",flag);
}

char* rounding(char* p){
    char* start=p;
    char* end=p;

    for(int i=0; ; i++)//结尾只有小数点或者\0
    {
        if(*(end+i)=='.'){
            end+=i;
            break;
        }

        if(*(end+i)=='\0'){
            end+=i;
            break;
        }
    }

    for(int i=0; ; i++)//如果知道结尾都是零就NULL
    {
        if(start+i==end)
            return NULL;
        if(*(start+i)=='-')
            continue;
        if(*(start+i)!='0'){
            start+=i;
            break;
        }
    }


    static char r[1000]={0};
    int i=0;
    if(*p=='-'){
        r[0]='-';
        for(i=0; (start+i)!=end; i++){
            r[i+1]=*(start+i);
        }
        r[i+1]='\0';
    }
    else{
        for(i=0; (start+i)!=end; i++){
            r[i]=*(start+i);
        }
        r[i]='\0';
    }

    return r;
}