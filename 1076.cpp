#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>

#define MAX_V 1100

using namespace std;

struct Node{
	int v;
	int level;
}user;

int n,l;
vector<Node> G[MAX_V];
bool visited[MAX_V];


void bfs(int start){
	visited[start]=true;
	int fowardNum=0;
	queue<Node> q;
	Node s;
	s.v=start;
	s.level=0;
	q.push(s);
	
	while(!q.empty()){
		Node p=q.front();
		q.pop();
		int u=p.v;
		for(int i=0;i<G[u].size();i++){
			Node next=G[u][i];
			next.level=p.level+1;
			if(!visited[next.v]&&next.level<=l){
				q.push(next);
				visited[next.v]=true;
				fowardNum++;
			}
		}
	}
	printf("%d\n",fowardNum);
}

int main(){
	int followNum;
	int follow;
	int queryNum;
	int start;
	scanf("%d%d",&n,&l);
	for(int i=1;i<=n;i++){
		user.v=i;
		scanf("%d",&followNum);
		for(int j=0;j<followNum;j++){
			scanf("%d",&follow);
			G[follow].push_back(user);
		}
	}
	scanf("%d",&queryNum);
	for(int i=0;i<queryNum;i++){
		memset(visited,false,sizeof(visited));
		scanf("%d",&start);
		bfs(start);
	}
}
