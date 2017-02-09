#include<stdio.h>
#include<algorithm>
#include<string.h> 
#include<iostream>

using namespace std;

struct stu{
    char id[15];
    int de,cai,sum;
    int flag;
}Stu[100100];

bool cmp(struct stu a,struct stu b){
    if(a.flag!=b.flag)  return a.flag<b.flag;
    if(a.sum!=b.sum)    return a.sum>b.sum;
    if(a.de!=b.de)      return a.de>b.de;
    return strcmp(a.id,b.id)<0;
}

int main(){
    int N,L,H;
    scanf("%d%d%d",&N,&L,&H);
    int pass=N;//及格人数 
    for(int i=0;i<N;i++){
        scanf("%s%d%d",Stu[i].id,&Stu[i].de,&Stu[i].cai);
        Stu[i].sum=Stu[i].de+Stu[i].cai;
        if(Stu[i].de<L||Stu[i].cai<L){
            pass--;
            Stu[i].flag=5; 
        }
        else if(Stu[i].de>=H&&Stu[i].cai>=H)    Stu[i].flag=1;
        else if(Stu[i].de>=H&&Stu[i].cai<H)     Stu[i].flag=2;
        else if(Stu[i].de>=Stu[i].cai)          Stu[i].flag=3;
        else    Stu[i].flag=4;
    }
    sort(Stu,Stu+N,cmp);
    printf("%d\n",pass);
    for(int i=0;i<pass;i++){
        printf("%s %d %d\n",Stu[i].id,Stu[i].de,Stu[i].cai);
    }
}
