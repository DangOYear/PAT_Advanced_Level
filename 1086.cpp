#include<stdio.h>
#include<queue>
#include<string.h>
#include<stack>

using namespace std;


#define MAX_N 37

int inorder[MAX_N],preorder[MAX_N];

typedef struct Node{
	int data;
	Node *lchild,*rchild;
}node,*Btree;

int n;

void create(Btree &bt,int preL,int preR,int inL,int inR){
	if(preL>preR){
		bt=NULL;
		return;
	}
	bt=new node;
	bt->data=preorder[preL];
	int leftnum;
	int i;
	for(i=inL;i<=inR;i++){
		if(inorder[i]==preorder[preL]){
			leftnum=i-inL;
			break;
		}
	}
	create(bt->lchild,preL+1,preL+leftnum,inL,i-1);
	create(bt->rchild,preL+leftnum+1,preR,i+1,inR);
}


void postorder(Btree root){
	static int count=0;
	if(root==NULL)
		return ;
	postorder(root->lchild);
	postorder(root->rchild);
	printf("%d",root->data);
	count++;
	if(count<n)	printf(" ");
}

int main(){
	
	scanf("%d",&n);
	char opr[5];
	int num;
	int preIndex=0,inIndex=0;
	stack<int> s;
	for(int i=0;i<2*n;i++){
		scanf("%s",opr);
		if(!strcmp(opr,"Push")){
			scanf("%d",&num);
			preorder[preIndex++]=num;
			s.push(num);
		}
		else{
			inorder[inIndex++]=s.top();
			s.pop();
		}
	}
	Btree root=NULL;
	create(root,0,n-1,0,n-1);
	postorder(root);
}
