#include<stdio.h>
#include<algorithm>
#include<queue>

using namespace std;

typedef struct Node{
	int weight;
	int height;
	Node *lchild,*rchild;
}AVLnode,*AVLtree;

AVLtree root;
int n;
AVLnode *newNode(int weight){
	AVLnode *node=new AVLnode;
	node->weight=weight;
	node->height=1;
	node->lchild=node->rchild=NULL;
	return node;
}

int getHeight(AVLtree root){
	if(root==NULL)	return 0;
	return root->height;
}

void updateHeight(AVLtree root){
	root->height=max(getHeight(root->lchild),getHeight(root->rchild))+1;
}

int getBalanceFactor(AVLtree root){
	return getHeight(root->lchild)-getHeight(root->rchild);
}

void L(AVLtree &root){
	AVLnode *temp=root->rchild;
	root->rchild=temp->lchild;
	temp->lchild=root;
	updateHeight(root);
	updateHeight(temp);
	root=temp;
}
void R(AVLtree &root){
	AVLnode *temp=root->lchild;
	//root->lchild=temp->lchild;
	root->lchild=temp->rchild;
	temp->rchild=root;
	updateHeight(root);
	updateHeight(temp);
	root=temp;
}

void insert(AVLtree &root,int weight){
	if(root==NULL){
		root=newNode(weight);
		return;
	}
	if(weight<root->weight){
		insert(root->lchild,weight);
		updateHeight(root);
		if(getBalanceFactor(root)==2){
			if(getBalanceFactor(root->lchild)==1){
				R(root);
			}
			else if(getBalanceFactor(root->lchild)==-1){
				L(root->lchild);
				R(root);
			}
		}
		
	}
	else{
		insert(root->rchild,weight);
		updateHeight(root);
		if(getBalanceFactor(root)==-2){
			if(getBalanceFactor(root->rchild)==-1){
				L(root);
			}
			else if(getBalanceFactor(root->rchild)==1){
				R(root->rchild);
				L(root);
			}
		}
	}
}

bool bfs(AVLnode *root){
	int count=0;
	queue<AVLnode*> q;
	q.push(root);
	bool flag=true;
	while(count<n){
		AVLnode* p=q.front();
		q.pop();
		if(p!=NULL){
			printf("%d",p->weight);
			count++;
			if(count!=n){
				printf(" ");
			}
			else{
				printf("\n");
			}
			q.push(p->lchild);
			q.push(p->rchild);
		}
		else{
			if(count<n){
				flag=false;
			}
		}
	}
	return flag;
}

int main(){
	int weight;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&weight);
		insert(root,weight);
	}
	//printf("%d",root->weight);
	bool flag=bfs(root);
	if(flag)
		printf("YES");
	else
		printf("NO");
}
