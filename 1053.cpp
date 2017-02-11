#include<stdio.h>
#include<vector>
#include<algorithm>

#define MAX_N 110

using namespace std;

struct Node{
	int weight;
	vector<int> child;
}node[MAX_N];

int n,m,Sum;

int path[MAX_N];

bool cmp(int a,int b){
	return node[a].weight>node[b].weight;
}



void dfs(int count,int Nodenum,int sum){
	if(sum>Sum)	return ;
	if(sum==Sum){
		if(node[count].child.size()!=0)	return;
		else{
			for(int i=0;i<Nodenum;i++){
				printf("%d",node[path[i]].weight);
				if(i!=Nodenum-1)
					printf(" ");
			}
			printf("\n");
			return;
		}
	}
	for(int i=0;i<node[count].child.size();i++){
		int child=node[count].child[i];
		path[Nodenum]=child;
		dfs(child,Nodenum+1,sum+node[child].weight);
	}
	
}

int main(){
	scanf("%d%d%d",&n,&m,&Sum);
	for(int i=0;i<n;i++){
		scanf("%d",&node[i].weight);
	}
	int id,k,child;
	for(int i=0;i<m;i++){
		scanf("%d%d",&id,&k);
		for(int j=0;j<k;j++){
			scanf("%d",&child);
			node[id].child.push_back(child);
		}
		sort(node[id].child.begin(),node[id].child.end(),cmp);
	}
	path[0]=0;
	dfs(0,1,node[0].weight);
}
