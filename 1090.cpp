#include<stdio.h>
#include<vector>
#include<queue>
#include<math.h>
#define MAX_N 100100
using namespace std;

struct Node{
	int level;
	vector<int> child;
}node[MAX_N];

int n;
double p,r;
int deep[MAX_N];


void bfs(int root,int level){
	node[root].level=level;
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int p=q.front();
		q.pop();
		deep[node[p].level]++;
		for(int i=0;i<node[p].child.size();i++){
			node[node[p].child[i]].level=node[p].level+1;
			q.push(node[p].child[i]);
		}
	}
}

int main(){
	scanf("%d%lf%lf",&n,&p,&r);
	r=r/100;
	int parent;
	int root;
	for(int i=0;i<n;i++){
		scanf("%d",&parent);
		if(parent!=-1){
			node[parent].child.push_back(i);
		}
		else{
			root=i;
		}
	}
	bfs(root,0);
	int maxdeep;
	for(int i=0;i<MAX_N;i++){
		if(deep[i]!=0){
			maxdeep=i;
		}
	}
	printf("%.2f %d",p*pow(1+r,maxdeep),deep[maxdeep]);
}
