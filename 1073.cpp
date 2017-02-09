#include<stdio.h>
#include<string.h>

#define MAX_N 10010

char str[MAX_N];

int main(){
    gets(str);
    int l=strlen(str);
    if(str[0]=='-') printf("-");
    int position=0;
    while(str[position]!='E'){
        position++;
    }
    int exp=0;
    for(int i=position+2;i<l;i++){
        exp=exp*10+str[i]-'0';
        //printf("%d\n",exp);
    }

    if(str[position+1]=='-'){
        printf("0.");
        for(int i=0;i<exp-1;i++){
            printf("0");
        }
        for(int i=1;i<position;i++){
            if(str[i]!='.')
                printf("%c",str[i]);
        }
    }else{
        for(int i=1;i<position;i++){
            if(str[i]!='.'){
                printf("%c",str[i]);
            }
            if(i==exp+2&&position-3!=exp){
                printf(".");
            }
        }

        for(int i=0;i<exp-(position-3);i++){
            //printf("%d\n",exp-(position-3));
            printf("0");
        }
    }

}
