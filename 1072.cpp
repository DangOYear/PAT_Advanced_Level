#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>

using namespace std;


#define MAX_V 1100
#define INF 1000000000

int G[MAX_V][MAX_V];
int n,m,k,ds;
int d[MAX_V];
bool visited[MAX_V];

void Dijkstra(int s){
	memset(visited,false,sizeof(visited));
	fill(d,d+MAX_V,INF);
	
	d[s]=0;
	for(int i=0;i<n+m;i++){
		int u=-1,Min=INF;
		for(int j=1;j<=n+m;j++){
			if(!visited[j]&&d[j]<Min){
				u=j;
				Min=d[j];
			}
		}
		if(u==-1)	return;
		visited[u]=true;
		for(int v=1;v<=n+m;v++){
			if(!visited[v]&&G[u][v]!=INF){
				if(d[u]+G[u][v]<d[v]){
					d[v]=d[u]+G[u][v];
				}
			}
		}
	}
}

int getID(char str[]){
	int len=strlen(str);
	int id=0;
	for(int i=0;i<len;i++){
		if(str[i]!='G'){
			id=id*10+str[i]-'0';
		}
	}
	if(str[0]=='G')	return n+id;
	return id;
}

int main(){
	scanf("%d%d%d%d",&n,&m,&k,&ds);
	char house1[5],house2[5];
	int dis,u,w;
	fill(G[0],G[0]+MAX_V*MAX_V,INF);
	for(int i=0;i<k;i++){
		scanf("%s %s %d",house1,house2,&dis);
		int u=getID(house1);
		int v=getID(house2);
		G[u][v]=G[v][u]=dis;
	}
	double ansDis=-1;
	double ansAvg=INF;
	
	int ansID=-1;

	for(int i=n+1;i<=n+m;i++){
		double min=INF,avg=0;
		Dijkstra(i);
		for(int j=1;j<=n;j++){
			if(d[j]>ds){
				min=-1;
				break;
			}
			if(d[j]<min)	min=d[j];
			avg+=1.0*d[j]/n;
		}
		if(min==-1)	continue;
		if(min>ansDis){
			ansDis=min;
			ansID=i;
			ansAvg=avg;
		}
		else{
			if(min==ansDis&&avg<ansAvg){
				ansID=i;
				ansAvg=avg;
			}
		}
	}
	
	if(ansID==-1)	printf("No Solution\n");
	else{
		printf("G%d\n",ansID-n);
		printf("%.1f %.1f",ansDis,ansAvg);
	}
}
