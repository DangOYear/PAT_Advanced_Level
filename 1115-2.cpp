#include<stdio.h>
#include<queue>

using namespace std;

#define MAX_N 1100


typedef struct Node{
	int data;
	Node *lchild,*rchild;
	int level;
}bsnode,*BStree;

int n;

int level[MAX_N];

void insert(BStree &root,int data){
	if(root==NULL){
		root=new bsnode;
		root->data=data;
		root->lchild=NULL;
		root->rchild=NULL;
		return ;
	}
	if(data<=root->data)	insert(root->lchild,data);
	else	insert(root->rchild,data);
}

//void in(BStree root){
//	if(root==NULL)
//		return;
//	in(root->lchild);
//	printf("%d ",root->data);
//	in(root->rchild);
//}

void bfs(BStree root){
	queue <bsnode*> q;
	root->level=0;
	q.push(root);
	int max=-1;
	while(!q.empty()){
		bsnode *node=q.front();
		q.pop();
		if(node->level>max){
			max=node->level;
		}
		if(node->lchild!=NULL){
			(node->lchild)->level=(node->level)+1;
			
			q.push(node->lchild);
			
		}
		if(node->rchild!=NULL){
			(node->rchild)->level=(node->level)+1;
			
			q.push(node->rchild);
		}
		level[node->level]++;
	}
	printf("%d + %d = %d\n",level[max],level[max-1],level[max]+level[max-1]);
}


int main(){
	scanf("%d",&n);
	int data;
	BStree root=NULL;
	for(int i=0;i<n;i++){
		scanf("%d",&data);
		insert(root,data);
	}
	//in(root);
	bfs(root);
}
