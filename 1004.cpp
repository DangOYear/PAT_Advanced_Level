#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;

#define MAX_N 110

struct Node{
	int level;
	vector<int> child;
}node[MAX_N];

int n,m;

int gene[MAX_N];
int maxlevel=-1;

void bfs(int root,int level){
	node[root].level=level;
	queue<int> q;
	q.push(root);	
	while(!q.empty()){
		int p=q.front();
		q.pop();
		if(node[p].level>maxlevel){
			maxlevel=node[p].level;
		}
		if(node[p].child.size()==0){
			gene[node[p].level]++;
		}
		for(int i=0;i<node[p].child.size();i++){
			node[node[p].child[i]].level=node[p].level+1;
			q.push(node[p].child[i]);
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	int id,k,child;
	for(int i=0;i<m;i++){
		scanf("%d%d",&id,&k);
		for(int j=0;j<k;j++){
			scanf("%d",&child);
			node[id].child.push_back(child);
		}
	}
	bfs(1,1);
	for(int i=1;i<=maxlevel;i++){
		printf("%d",gene[i]);
		if(i!=maxlevel)
			printf(" ");
	}
}
