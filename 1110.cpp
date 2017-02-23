#include<stdio.h>
#include<queue>
#include<stdlib.h>
#include<string.h>

using namespace std;

#define MAX_N 25


struct Node{
	int lchild,rchild;
	Node(){
		lchild=-1;
		rchild=-1;
	}
}node[MAX_N];

int n;
bool visited[MAX_N];

int trans(int i,char child[]){
	if(strcmp(child,"-")==0)
		return -1;
	else{
		int num=atoi(child);
		visited[num]=true;
		return num;
	}
	
}

int findroot(){
	for(int i=0;i<n;i++){
		if(!visited[i]){
			return i;
		}
	}
}

int bfs(int root){
	queue<int> q;
	q.push(root);
	int m=0;
	int last;
	while(q.front()!=-1){
		int p=q.front();
		q.pop();
		last=p;
		m++;
		q.push(node[p].lchild);
		q.push(node[p].rchild);
	}
	if(m==n)
		return last;
	else
		return -1;
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		char lchild[5],rchild[5];
		scanf("%s %s",&lchild,&rchild);
		node[i].lchild=trans(i,lchild);
		node[i].rchild=trans(i,rchild);
	}
	int root=findroot();
	//printf("%d",root);
	int flag=bfs(root);
	if(flag==-1){
		printf("NO %d",root);
	}
	else{
		printf("YES %d",flag);
	}
}
