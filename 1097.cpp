#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<stdlib.h>

#define MAX_N 100100

#define MAX_K 10100

using namespace std;
struct Node{
	int address;
	int data;
	int next;
	int order;
}node[MAX_N];

bool visited[MAX_K];

int n;
int head;

bool cmp(struct Node a,struct Node b){
	return a.order<b.order;
}

void init(){
	for(int i=0;i<MAX_N;i++){
		node[i].order=2*MAX_N;
	}
}

int main(){
	int address;
	init();
	scanf("%d%d",&head,&n);
	for(int i=0;i<n;i++){
		scanf("%d",&address);
		scanf("%d%d",&node[address].data,&node[address].next);
		node[address].address=address;
	}
	int validnum=0,removednum=0;
	for(int p=head;p!=-1;p=node[p].next){
		if(!visited[abs(node[p].data)]){
			visited[abs(node[p].data)]=true;
			node[p].order=validnum++;
		}
		else{
			node[p].order=MAX_N+removednum++;
		}
	}
	
	sort(node,node+MAX_N,cmp);
	int validnode=validnum+removednum;
	for(int i=0;i<validnode;i++){
		if(i!=validnum-1&&i!=validnode-1){
			printf("%05d %d %05d\n",node[i].address,node[i].data,node[i+1].address);
		}
		else{
			printf("%05d %d -1\n",node[i].address,node[i].data);
		}
	}
}
