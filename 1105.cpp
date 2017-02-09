#include<stdio.h>
#include<math.h>
#include<algorithm>

using namespace std;

int N;
int m,n;
#define MAX_N 11000

int a[MAX_N][MAX_N];
int num[MAX_N];

bool cmp(int a,int b){
    return a>b;
}

void cal_m_n(){
    int sqt=(int)sqrt(N);
    for(int i=1;i<=sqt;i++){
        if(N%i==0)
            n=i;
    }
    m=N/n;
}

void print(){
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            printf("%d",a[i][j]);
            if(j!=n)
                printf(" ");
        }
        printf("\n");
    }
}

int col_s,col_e,raw_s,raw_e;
int i=1,j=1;
int start;


int main(){

    scanf("%d",&N);

    for(int i=0;i<N;i++){
        scanf("%d",&num[i]);
    }
    if(N==1){
        printf("%d",num[0]);
        return 0;
    }
    cal_m_n();
    sort(num,num+N,cmp);
    col_s=1;col_e=m;raw_s=1;raw_e=n;
    while(start<N){
        while(start<N&&j<raw_e){
                a[i][j]=num[start++];
                j++;
            }

            while(start<N&&i<col_e){
                a[i][j]=num[start++];
                i++;
            }

            while(start<N&&j>raw_s){
                a[i][j]=num[start++];
                j--;
            }
            while(start<N&&i>col_s){
                a[i][j]=num[start++];
                i--;
            }
            col_s++;col_e--;raw_s++;raw_e--;
            i++;j++;
            if(start==N-1){
            a[i][j]=num[start++];
        }
    }


    //solve();
    print();
}
