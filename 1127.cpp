#include<stdio.h>
#include<queue>
#include<algorithm> 
#define MAX_N 32

using namespace std;


typedef struct Node {
	Node *lchild;
	Node *rchild;
	int data;
	int level;
}node,*BTtree;

int in[MAX_N],post[MAX_N];
int n;
int level[MAX_N];//对应层数的个数
int num[MAX_N];//全部数值 
int maxLevel=0;
//vector<vector<int> > v(MAX_N);

void build(BTtree &root,int inL,int inR,int postL,int postR){
	if(inL>inR){
		return;
	}
	int m;
	for(int i=inL;i<=inR;i++){
		if(in[i]==post[postR]){
			m=i;
			break;
		}
	}
	if(root==NULL){
		root=new node;
		root->data=in[m];
		root->lchild=root->rchild=NULL;
		//return ;
	}
	build(root->lchild,inL,m-1,postL,postL+m-inL-1);
	build(root->rchild,m+1,inR,postR-inR+m,postR-1);
}

//void pre(BTtree root){
//	if(root==NULL)
//		return;
//	printf("%d ",root->data);
//	pre(root->lchild);
//	pre(root->rchild);
//}

void bfs(BTtree root){
	int count=0;
	queue<BTtree> q;
	root->level=1;
	q.push(root);
	while(!q.empty()){
		BTtree p=q.front();
		q.pop();
		level[p->level]++;
		if(p->level>maxLevel){
			maxLevel=p->level;
		}
		//printf("%d ",p->data);
		num[count++]=p->data; 
		if(p->lchild!=NULL){
			p->lchild->level=p->level+1;
			q.push(p->lchild);
		}
		if(p->rchild!=NULL){
			p->rchild->level=p->level+1;
			q.push(p->rchild);
		}
	}
}

void trans(int L,int R){
	int m=(L+R)/2;
	for(int i=L;i<=m;i++){
		int temp=num[i];
		num[i]=num[R-(i-L)];
		num[R-(i-L)]=temp;
	}
}

int main(){
	BTtree root=NULL;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&in[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&post[i]);
	}
	build(root,0,n-1,0,n-1);
	bfs(root);

	
	int pos=0;
	for(int i=1;i<=maxLevel;i++){
		if(i%2==1)
			trans(pos,pos+level[i]-1);
		for(int j=0;j<level[i];j++){
			printf("%d",num[pos++]);
			if(pos!=n){
				printf(" ");
			}
		}
	}
}

