#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

#define MAX_V 520
#define INF 1000000000

int G[MAX_V][MAX_V];
int set[MAX_V];
int n,m;
int d[MAX_V];


int find(int r){
	while(r!=set[r]){
		r=set[r];
	}
	return r;
}

void Union(int a,int b){
	int fa=find(a);
	int fb=find(b);
	if(fa!=fb)
		set[fa]=fb;
}

void init(){
	for(int i=1;i<MAX_V;i++){
		set[i]=i;
	}
}

int judge(){
	int count=0;
	for(int i=1;i<=n;i++){
		if(set[i]==i){
			count++;
		}
	}
	if(count>1)	return 0;
	bool flag=true;
	int f=0;
	for(int i=1;i<=n;i++){
		if(d[i]%2==1){
			flag=false;
			f++;
		}
	}
	if(f==2)	return 1;
	if(flag)	return 2;
	return 0;
}

int main(){
	scanf("%d%d",&n,&m);
	fill(G[0],G[0]+MAX_V*MAX_V,INF);
	init();
	int u,v;
	for(int i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		Union(u,v);
		G[u][v]=G[v][u]=0;
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(G[i][j]==0){
				d[i]++;
				d[j]++;
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		d[i]/=2;
		printf("%d",d[i]);
		if(i!=n){
			printf(" ");
		}
	}
	printf("\n");
	int type=judge();
	if(type==0)	printf("Non-Eulerian");
	if(type==1)	printf("Semi-Eulerian");
	if(type==2)	printf("Eulerian");
}
