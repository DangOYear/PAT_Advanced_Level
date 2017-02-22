#include<stdio.h>
#include<queue>

using namespace std;

#define MAX_N 1100

struct Node{
	int data;
	int lchild,rchild;
	int level;
}node[MAX_N];

int n;




void insert(int i,int root){
	if(root==-1){
		root=i;
	}
	else{
		if(node[i].data<node[root].data)	insert(i,node[root].lchild);
		else	insert(i,node[root].rchild);
	}
}

void in(int &root){
	
	in(node[root].lchild);
	printf(" %d",node[root].data);
	in(node[root].rchild);
}


void bfs(int root){
	printf("bfs\n");
	queue<int> q;
	int max=-1;
	node[root].level=1;
	q.push(root);
	while(!q.empty()){
		int p=q.front();
		q.pop();
		if(node[p].lchild!=-1){
			node[node[p].lchild].level=node[p].level+1;
			if(node[node[p].lchild].level>max){
				max=node[node[p].lchild].level;
			}
			q.push(node[p].lchild);
		}
		if(node[p].rchild!=-1){
			node[node[p].rchild].level=node[p].level+1;
			if(node[node[p].rchild].level>max){
				max=node[node[p].rchild].level;
			}
			q.push(node[p].rchild);
		}
	}
	int n1=0,n2=0;
	for(int i=0;i<n;i++){
		if(node[i].level==max){
			n1++;
		}
		if(node[i].level==max-1){
			n2++;
		}
	}
	printf("%d + %d = %d",n1,n2,n1+n2);
}

int main(){
	int num;
	int root=-1;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&num);
		node[i].data=num;
		node[i].lchild=node[i].rchild=-1;
		insert(i,root);
	}
	in(root);
	bfs(root);
}
