#include<stdio.h>
#include<set>
#include<vector>

using namespace std;

#define MAX_N 10100

set<int> temp,ans;
vector<int> G[MAX_N];
bool isRoot[MAX_N];
int father[MAX_N];

int n;

int find(int x){
	int r=x;
	while(r!=father[r]){
		r=father[r];
	}
	return r;
}

void merge(int a,int b){
	int fa=find(a);
	int fb=find(b);
	if(fa!=fb){
		father[fa]=fb;
	}
}

void init(){
	for(int i=1;i<=n;i++){
		father[i]=i;
	}
}

int findRoot(){
	int count=0;
	for(int i=1;i<=n;i++){
		isRoot[find(i)]=true;
	}
	for(int i=1;i<=n;i++){
		if(isRoot[i]){
			count++;
		}
	}
	//printf("count=%d\n",count);
	return count;
}

int maxh=0;

void dfs(int u,int height,int pre){
	if(height>maxh){
		temp.clear();
		temp.insert(u);
		maxh=height;
	}
	else if(height==maxh){
		temp.insert(u);
	}
	for(int i=0;i<G[u].size();i++){
		if(G[u][i]==pre)	continue;
		else	dfs(G[u][i],height+1,u);
	}
}


int main(){
	scanf("%d",&n);
	init();
	int a,b;
	for(int i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
		merge(a,b);
	}
	int flag=findRoot();
	if(flag!=1){
		printf("Error: %d components\n",flag);
	}
	else{
		dfs(1,1,-1);
		ans=temp;
		dfs(*(ans.begin()),1,-1);
		for(set<int>::iterator it=temp.begin();it!=temp.end();it++){
			ans.insert(*it);
		}
		for(set<int>::iterator it=ans.begin();it!=ans.end();it++){
			printf("%d\n",*it);
		}
	}
}
