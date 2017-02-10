#include<stdio.h>
#include<queue>
#include<math.h>
#include<vector>

using namespace std;

#define MAX_N 100100

struct Node{
	int level;
	vector<int> child;
}node[MAX_N];

int n;
double p,r;
int num;
int minLevel=-1;
void bfs(int root,int level){
	node[root].level=level;
	queue<int> q;
	bool flag=false;
	q.push(root);
	while(!q.empty()){
		int p=q.front();
		q.pop();
		if(node[p].child.size()==0&&!flag){
			flag=true;
			minLevel=node[p].level;
			//printf("%d\n",minLevel);
		}
		if(node[p].level>minLevel&&flag){
			break;
		}
		if(node[p].level==minLevel&&node[p].child.size()==0){
			//printf("P %d\n",p);
			num++;
		}
		for(int i=0;i<node[p].child.size();i++){
			node[node[p].child[i]].level=node[p].level+1;
			q.push(node[p].child[i]);
		}
	}
	
}

int main(){
	scanf("%d%lf%lf",&n,&p,&r);
	r=r/100;
	int k;
	int child;
	for(int i=0;i<n;i++){
		scanf("%d",&k);
		if(k!=0){
			for(int j=0;j<k;j++){
				scanf("%d",&child);
				node[i].child.push_back(child);
			}
		}
	}
	bfs(0,0);
	//printf("%d\n",minLevel);
	printf("%.4f %d",p*pow(1+r,minLevel),num);
}
