#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;

#define MAX_V 510
#define INF 100000000



int n,m;
int Start,End;
int G[MAX_V][MAX_V];
int d[MAX_V];
int cost[MAX_V][MAX_V];
int minCost=INF;
bool visited[MAX_V];
vector<int> pre[MAX_V];

vector<int> temp,shortestPath;

void Dijkstra(int s){
	fill(d,d+MAX_V,INF);
	d[s]=0;
	for(int i=0;i<n;i++){
		int u=-1,Min=INF;
		for(int j=0;j<n;j++){
			if(!visited[j]&&d[j]<Min){
				u=j;
				Min=d[j];
			} 
		}
		if(u==-1)	return;
		visited[u]=true;
		for(int v=0;v<n;v++){
			if(!visited[v]&&G[u][v]!=INF){
				if(d[u]+G[u][v]<d[v]){
					d[v]=d[u]+G[u][v]; 
					pre[v].clear();
					pre[v].push_back(u);
				}else if(d[u]+G[u][v]==d[v]){
					pre[v].push_back(u);
				}
			}
		}
	}
}

void DFS(int v){
	if(v==Start){
		temp.push_back(v);
		int tempCost=0;
		for(int i=temp.size()-1;i>0;i--){
			int vertex=temp[i],vertexNext=temp[i-1];
			tempCost+=cost[vertex][vertexNext];	
		}
		if(tempCost<minCost){
			minCost=tempCost;
			shortestPath=temp;
		}
		temp.pop_back();
		return;
	}
	
	temp.push_back(v);
	for(int i=0;i<pre[v].size();i++){
		DFS(pre[v][i]);
	}
	temp.pop_back(); 
}

int main(){
	scanf("%d%d%d%d",&n,&m,&Start,&End);
	int u,v;
	fill(G[0],G[0]+MAX_V*MAX_V,INF);
	fill(cost[0],cost[0]+MAX_V*MAX_V,INF);

	
	for(int i=0;i<m;i++){
		scanf("%d %d",&u,&v);
		scanf("%d %d",&G[u][v],&cost[u][v]);
		G[v][u]=G[u][v];
		cost[v][u]=cost[u][v];
	}
	
	Dijkstra(Start);
	DFS(End);
	for(int i=shortestPath.size()-1;i>=0;i--){
		printf("%d ",shortestPath[i]);
	}
	printf("%d %d",d[End],minCost);
}
