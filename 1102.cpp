#include<stdio.h>
#include<queue>
#include<string.h>
#include<stack>

using namespace std;


#define MAX_N 37

int n;

struct Node{
	int lchild,rchild;
	
}node[MAX_N];

bool visited[MAX_N]={false};

int strTonum(char c){
	if(c=='-')	return -1;
	visited[c-'0']=true;
	return c-'0';
}

void reverse(int root){
	if(root==-1)
		return;
	reverse(node[root].lchild);
	reverse(node[root].rchild);
	
	int temp=node[root].lchild;
	node[root].lchild=node[root].rchild;
	node[root].rchild=temp;
}

void level(int root){
	int count=0;
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int p=q.front();
		q.pop();
		count++;
		printf("%d",p);
		if(count<n)	printf(" ");
		else	printf("\n");
		
		if(node[p].lchild!=-1)	q.push(node[p].lchild);
		if(node[p].rchild!=-1)	q.push(node[p].rchild);
	}
}

void inorder(int root){
	static int count=0;
	if(root==-1)
		return ;
	inorder(node[root].lchild);
	printf("%d",root);
	count++;
	if(count<n)	printf(" ");
	inorder(node[root].rchild);
	
}

int main(){
	scanf("%d",&n);
	char lchild,rchild;
	
	for(int i=0;i<n;i++){
		getchar();
		scanf("%c %c",&lchild,&rchild);
		node[i].lchild=strTonum(lchild);
		node[i].rchild=strTonum(rchild);
	}
	int root;
	for(int i=0;i<n;i++){
		if(!visited[i])
			root=i;
	}
	//printf("%d\n",root);
	reverse(root);
	level(root);
	inorder(root);
}
