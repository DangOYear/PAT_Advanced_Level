#include<stdio.h>
#include<queue>
#include<algorithm>

#define MAX_N 110
using namespace std;

struct Node{
	int data;
	int lchild,rchild;
}node[MAX_N];

int n;
int inorder[MAX_N];
int co=0;

void inOrder(int root){
	if(root==-1){
		return ;
	}
	inOrder(node[root].lchild);
	node[root].data=inorder[co++];
	//printf("%d",node[root].data);
	inOrder(node[root].rchild);
}

void BFS(int root){
	queue<int> q;
	q.push(root);
	int i=0;
	while(!q.empty()){
		int p=q.front();
		q.pop();
		printf("%d",node[p].data);
		i++;
		if(i!=n)	printf(" ");
		if(node[p].lchild!=-1)	q.push(node[p].lchild);
		if(node[p].rchild!=-1)	q.push(node[p].rchild);
	} 
}
int main(){
	scanf("%d",&n);
	int lchild,rchild;
	for(int i=0;i<n;i++){
		scanf("%d%d",&lchild,&rchild);
		node[i].lchild=lchild;
		node[i].rchild=rchild;
	}
	for(int i=0;i<n;i++){
		scanf("%d",&inorder[i]);
	}
	sort(inorder,inorder+n);
//	for(int i=0;i<n;i++){
//		printf("%d",inorder[i]);
//	}
	inOrder(0);
	BFS(0);
} 
