#include<stdio.h>
#include<algorithm>


using namespace std;

#define MAX_N 100100

struct Node{
    int address;
    int next;
    int data;
    int order;
}node[MAX_N];

bool cmp(struct Node a,struct Node b){
    return a.order<b.order;
}


int main(){
    for(int i=0;i<MAX_N;i++){
        node[i].order=MAX_N;
    }
    int begin;
    int n;
    int k;
    scanf("%d%d%d",&begin,&n,&k);
    int address;
    for(int i=0;i<n;i++){
        scanf("%d",&address);
        scanf("%d%d",&node[address].data,&node[address].next);
        node[address].address=address;
    }
    int count=0;
    for(int p=begin;p!=-1;p=node[p].next){
        node[p].order=count++;
    }
    sort(node,node+MAX_N,cmp);
    n=count;
    for(int i=0;i<n/k;i++){
        for(int j=(i+1)*k-1;j>i*k;j--){
            printf("%05d %d %05d\n",node[j].address,node[j].data,node[j-1].address);
        }
        printf("%05d %d ",node[i*k].address,node[i*k].data);
        if(i<n/k-1){
            printf("%05d\n",node[(i+2)*k-1].address);
        }
        else{
            if(n%k==0){
                printf("-1\n");
            }
            else{
                printf("%05d\n",node[(i+1)*k].address);
                for(int l=n/k*k;l<n;l++){
                    printf("%05d %d ",node[l].address,node[l].data);
                    if(l!=n-1)
                        printf("%05d\n",node[l+1].address);
                    else
                        printf("-1\n");
                }


            }

        }

    }

}
