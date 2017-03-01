#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
using namespace std;

#define MAX_V 510
#define INF 1000000000

int G[MAX_V][MAX_V];
int n,m,Cmax,Sp;
bool visited[MAX_V];
int weight[MAX_V];
int w[MAX_V];
int MinNeed=INF;
int MinRemain=INF;
int d[MAX_V];
vector<int> pre[MAX_V];
vector<int> temp,path;

void Dijkstra(int s){
	fill(d,d+MAX_V,INF);
	d[s]=0;
	for(int i=0;i<=n;i++){
		int u=-1,Min=INF;
		for(int j=0;j<=n;j++){
			if(!visited[j]&&d[j]<Min){
				u=j;
				Min=d[j];
			}
		}
		if(u==-1)	return ;
		visited[u]=true;
		for(int v=0;v<=n;v++){
			if(!visited[v]&&G[u][v]!=INF){
				if(d[u]+G[u][v]<d[v]){
					d[v]=d[u]+G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if(d[u]+G[u][v]==d[v]){
					pre[v].push_back(u);
				}
			}
		}
	}
}

void DFS(int v){
	if(v==0){
		temp.push_back(v);
		int need=0,remain=0;
		for(int i=temp.size()-1;i>=0;i--){
			int vertex=temp[i];
			if(weight[vertex]>0){
				remain+=weight[vertex];
			}
			else{
				if(remain>abs(weight[vertex])){
					remain-=abs(weight[vertex]);
				}
				else{
					need+=abs(weight[vertex])-remain;
					remain=0;
				}
			}
		}
		if(need<MinNeed){
			MinNeed=need;
			MinRemain=remain;
			path=temp;
		}else if(need==MinNeed&&remain<MinRemain){
			MinRemain=remain;
			path=temp;
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
	scanf("%d%d%d%d",&Cmax,&n,&Sp,&m);
	fill(G[0],G[0]+MAX_V*MAX_V,INF);
	for(int i=1;i<=n;i++){
		scanf("%d",&weight[i]);
		weight[i]-=Cmax/2;
	}
	int u,v;
	for(int i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		scanf("%d",&G[u][v]);
		G[v][u]=G[u][v];
	}
	Dijkstra(0);
	DFS(Sp);
	printf("%d ",MinNeed);
	for(int i=path.size()-1;i>=0;i--){
		printf("%d",path[i]);
		if(i>0)	printf("->");
	}
	printf(" %d",MinRemain);
}
