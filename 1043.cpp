#include<stdio.h>
#include<vector>

using namespace std;

typedef struct Node{
	int data;
	struct Node *lchild,*rchild; 
}BTnode,*BTree;

int n;
vector<int> ori,pre,preM,post,postM;


void insert(BTree &root,int data){
	if(root==NULL){
		root=new BTnode;
		root->data=data;
		root->lchild=root->rchild=NULL;
		return;
	}
	if(data<root->data)	insert(root->lchild,data);
	else insert(root->rchild,data);
}


void PreOrder(BTree root,vector<int> &v){
	if(root==NULL)
		return;
	v.push_back(root->data);
	PreOrder(root->lchild,v);
	PreOrder(root->rchild,v);
}

void PreOrderMirror(BTree root,vector<int> &v){
	if(root==NULL)
		return;
	v.push_back(root->data);
	PreOrderMirror(root->rchild,v);
	PreOrderMirror(root->lchild,v);
}

void PostOrder(BTree root,vector<int> &v){
	if(root==NULL)
		return;
	PostOrder(root->lchild,v);
	PostOrder(root->rchild,v);
	v.push_back(root->data);
}

void PostOrderMirror(BTree root,vector<int> &v){
	if(root==NULL)
		return;
	PostOrderMirror(root->rchild,v);
	PostOrderMirror(root->lchild,v);
	v.push_back(root->data);
}

int main(){
	scanf("%d",&n);
	int data;
	BTree root=NULL;
	for(int i=0;i<n;i++){
		scanf("%d",&data);
		ori.push_back(data);
		insert(root,data);
	}
	
	PreOrder(root,pre);
	PreOrderMirror(root,preM);
	PostOrder(root,post);
	PostOrderMirror(root,postM);
	
	if(ori==pre){
		printf("YES\n");
		for(int i=0;i<post.size();i++){
			printf("%d",post[i]);
			if(i!=post.size()-1)
				printf(" ");
		} 
	}
	else if(ori==preM){
		printf("YES\n");
		for(int i=0;i<postM.size();i++){
			printf("%d",postM[i]);
			if(i!=postM.size()-1)
				printf(" ");
		}
	}
	else{
		printf("NO\n");
	}
} 

