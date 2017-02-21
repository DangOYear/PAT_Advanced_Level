#include<stdio.h>
#include<algorithm>

using namespace std;

#define MAX_N 100005
//const int MAX_N=100005
struct Node{
	int next;
	int data;
	int address;
	bool flag;
}node[MAX_N];

int n,head;

bool cmp(struct Node a,struct Node b){
	if(a.flag!=b.flag)	return a.flag>b.flag;
	else	return a.data<b.data;
	//if(a.data!=b.data)	return a.data<b.data; 
	//不处理相等的情况会出现段错误 
}

int main(){
	int address;
	scanf("%d%d",&n,&head);
	for(int i=0;i<n;i++){
		scanf("%d",&address);
		scanf("%d%d",&node[address].data,&node[address].next);
		node[address].address=address;
	}
	int count=0;
	for(int p=head;p!=-1;p=node[p].next){
		node[p].flag=true;
		count++;
	}
	if(count==0)
		printf("0 -1");
	else{
		sort(node,node+MAX_N,cmp);
		printf("%d %05d\n",count,node[0].address);
		for(int i=0;i<count;i++){
			if(i!=count-1)
				printf("%05d %d %05d\n",node[i].address,node[i].data,node[i+1].address);
			else
				printf("%05d %d -1\n",node[i].address,node[i].data);	
		}
	}
}
