#include<stdio.h>
#include<queue>



using namespace std;


#define MAX_N 37

int inorder[MAX_N],postorder[MAX_N];

typedef struct Node{
	int data;
	Node *lchild,*rchild;
}node,*Btree;

void create(Btree &bt,int posL,int posR,int inL,int inR){
	if(posL>posR){
		bt=NULL;
		return;
	}
	bt=new node;
	bt->data=postorder[posR];
	int leftnum;
	int i;
	for(i=inL;i<=inR;i++){
		if(inorder[i]==postorder[posR]){
			leftnum=i-inL;
			break;
		}
	}
	create(bt->lchild,posL,posL+leftnum-1,inL,i-1);
	create(bt->rchild,posL+leftnum,posR-1,i+1,inR);
}

void preorder(Btree root){
	if(root==NULL)
		return ;
	else{
		
		preorder(root->lchild);
		printf("%d ",root->data);
		preorder(root->rchild);
	}
}

void level(Btree root,int n){
	queue<Btree> q;
	int count=0;
	q.push(root);
	while(!q.empty()){
		Btree bt=q.front();
		q.pop();
		printf("%d",bt->data);
		count++;
		if(count<n)	printf(" ");
		if(bt->lchild)	{q.push(bt->lchild);}
		if(bt->rchild)	{q.push(bt->rchild);}
	}
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&postorder[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&inorder[i]);
	}
	Btree root=NULL;
	create(root,0,n-1,0,n-1);
	level(root,n);
	//preorder(root);
}
