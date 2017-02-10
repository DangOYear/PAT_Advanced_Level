#include<stdio.h>
#include<vector>
#include<queue>

#define MAX_N 110

using namespace std;

struct Node{
	int level;
	vector<int> child;
}node[MAX_N];

int gene[MAX_N];

int n;
int m;


void bfs(int root,int level){
	node[root].level=1;
	//gene[level]++;
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int p=q.front();
		q.pop();
		gene[node[p].level]++;
		for(int i=0;i<node[p].child.size();i++){
			node[node[p].child[i]].level=node[p].level+1;
			q.push(node[p].child[i]);
		}
	}
}

int main(){
	int id,k;
	int child;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&id,&k);
		for(int j=0;j<k;j++){
			scanf("%d",&child);
			node[id].child.push_back(child);
		}
	}
	bfs(1,1);
	int maxLevel=0,max=0;
	for(int i=1;i<MAX_N;i++){
		if(gene[i]>max){
			max=gene[i];
			maxLevel=i;
		}
	}
	printf("%d %d",max,maxLevel);
}
