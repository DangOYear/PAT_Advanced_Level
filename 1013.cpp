#include<stdio.h>
#include<vector>
#include<string.h>

#define MAX_N 1111
using namespace std;

vector<int> G[MAX_N];
bool visited[MAX_N];

int deletePoint;
int n,m,k;

void dfs(int v){
	if(v==deletePoint) return;
	visited[v]=true;
	for(int i=0;i<G[v].size();i++){
		if(!visited[G[v][i]]){
			dfs(G[v][i]);
		}
	}
}


int main(){
	
	int a,b;
	
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for(int i=0;i<k;i++){
		scanf("%d",&deletePoint);
		for(int i=0;i<MAX_N;i++){
			visited[i]=false;
		}
		int block=0;
		for(int i=1;i<=n;i++){
			if(i!=deletePoint&&!visited[i]){
				dfs(i);
				block++;
			}
		}
		printf("%d\n",block-1);
	}
}
