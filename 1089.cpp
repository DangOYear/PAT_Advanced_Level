#include<stdio.h>
#include<algorithm>
#define MAX_N 110

using namespace std;


int n;

int aim[MAX_N];
int ins[MAX_N];
int merg[MAX_N];

bool isSame(int a[],int b[]){
    bool flag=true;
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]){
            flag=false;
            return false;
        }
    }
    return true;
}

void show(int a[]){
    for(int i=0;i<n;i++){
        printf("%d",a[i]);
        if(i!=n-1)  printf(" ");
    }
    printf("\n");
}



bool insert(){
    bool flag=false;
    for(int i=1;i<n;i++){
        if(i!=1&&isSame(ins,aim)){
            flag=true;
        }

        int key=ins[i];
        int j=i;
        while(j>0&&ins[j-1]>key){
            ins[j]=ins[j-1];
            j=j-1;
        }
        ins[j]=key;

        if(flag){
            return true;
        }
    }
    return false;
} 

void mergesort(){
    bool flag=false;
    for(int i=2;i/2<=n;i*=2){
        if(i!=2&&isSame(aim,merg)){
            flag=true;
        }
        for(int j=0;j<n;j+=i){
            sort(merg+j,merg+min(j+i,n));
        }
        if(flag){
            show(merg);
            return ;
        }
    }
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&ins[i]);
        merg[i]=ins[i];
    }
    for(int i=0;i<n;i++){
        scanf("%d",&aim[i]); 
    }
    if(insert()){
        printf("Insertion Sort\n");
        show(ins);
    }
    else{
        printf("Merge Sort\n");
        mergesort();
    }


}
