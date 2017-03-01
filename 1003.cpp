#include<stdio.h>
#include<string.h>
#include<vector>

using namespace std;

#define MAX_V 510
#define INF 1000000000
int G[MAX_V][MAX_V];
int weight[MAX_V];
bool visited[MAX_V];
int n,m;
int num[MAX_V];
int w[MAX_V];
int d[MAX_V];

void Dijkstra(int s){
	fill(d,d+MAX_V,INF);
	memset(num,0,sizeof(num));
	memset(w,0,sizeof(w));
	d[s]=0;
	w[s]=weight[s];
	num[s]=1;
	for(int i=0;i<n;i++){
		int u=-1,Min=INF;
		for(int j=0;j<n;j++){
			if(!visited[j]&&d[j]<Min){
				u=j;
				Min=d[j];
			}
		}
		if(u==-1)	return ;
		visited[u]=true;
		for(int v=0;v<n;v++){
			if(!visited[v]&&G[u][v]!=INF){
				if(d[u]+G[u][v]<d[v]){
					d[v]=d[u]+G[u][v];
					w[v]=w[u]+weight[v];
					num[v]=num[u];
				}
				else if(d[u]+G[u][v]==d[v]){
					if(w[u]+weight[v]>w[v]){
						w[v]=w[u]+weight[v];
					}
					num[v]+=num[u];
				}
			}
		}
	}
}

int main(){
	int c1,c2;
	scanf("%d%d%d%d",&n,&m,&c1,&c2);
	for(int i=0;i<n;i++){
		scanf("%d",&weight[i]);
	}
	int u,v;
	fill(G[0],G[0]+MAX_V*MAX_V,INF);
	for(int i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		scanf("%d",&G[u][v]);
		G[v][u]=G[u][v];
	}
	Dijkstra(c1);
	printf("%d %d",num[c2],w[c2]);
}
