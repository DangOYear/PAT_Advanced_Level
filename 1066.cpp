#include<stdio.h>
#include<algorithm>


typedef struct Node{
	int weight;
	int height;
	Node *lchild,*rchild;
}AVLnode,*AVLtree;

AVLtree root;

AVLnode *newNode(int weight){
	AVLnode *node=new AVLnode;
	node->weight=weight;
	node->height=1;
	node->lchild=node->rchild=NULL:
	return node;
}

int getHeight(AVLtree root){
	if(root==NULL)	return 0;
	return root->height;
}

void updateHeight(AVLtree root){
	root->height=max(root->lchild->height,root->rchild->height)+1;
}

int getBalanceFactor(AVLtree root){
	return getHeight(root->lchild)-getHeight(root->rchild);
}

void L(AVLtree &root){
	AVLnode *temp=root->rchild;
	
}

void insert(AVLtree &root,int weight){
	if(root==NULL){
		root=newNode(weight);
		return;
	}
	
}


int main(){
	int n,weight;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&weight);
		insert(root,weight);
	}
}
