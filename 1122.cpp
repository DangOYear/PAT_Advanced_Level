#include<stdio.h>
#include<vector>
#define MAX_V 210
#define INF 100000000
#include<algorithm>
using namespace std;

int G[MAX_V][MAX_V];

int n,m;
int k;
int len;
vector<int> h;

bool judge(){
	if(h.size()!=n+1)	return false;
	if(h[0]!=h[h.size()-1])	return false;
	vector<int> temp(h.begin(),h.end()-1);
	sort(temp.begin(),temp.end());
	for(int i=0;i<temp.size();i++){
		if(temp[i]!=i+1)	return false;
	}
	for(int i=0;i<h.size()-1;i++){
		int u=h[i],v=h[i+1];
		if(G[u][v]==INF)	return false;
	}
	return true;
}

int main(){
	fill(G[0],G[0]+MAX_V*MAX_V,INF);
	scanf("%d%d",&n,&m);
	int V1,V2;
	int v;
	for(int i=0;i<m;i++){
		scanf("%d%d",&V1,&V2);
		G[V1][V2]=G[V2][V1]=0;
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		int N;
		scanf("%d",&N);
		h.clear();
		for(int i=0;i<N;i++){
			scanf("%d",&v);
			h.push_back(v);
		}
		if(judge()){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
}
