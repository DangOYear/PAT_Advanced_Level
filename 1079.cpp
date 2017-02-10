#include<stdio.h>
#include<math.h>
#include<queue>
#include<vector>

#include<algorithm>
#define MAX_N 100100

using namespace std;

int n;
double p,r;
double result=0.0;
struct Node{
	double data;
	vector<int> child;
	int level;
}node[MAX_N];

void bfs(int root,int level){
	node[root].level=level;
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int p=q.front();
		q.pop();
		if(node[p].child.size()==0){
			result+=node[p].data*pow(1+r,node[p].level);
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
		if(k==0){
			scanf("%lf",&node[i].data);
		}
		else{
			for(int j=0;j<k;j++){
				scanf("%d",&child);
				node[i].child.push_back(child);
			}
		}
	}
	bfs(0,0);
	
	//printf("%f\n",result);
	printf("%.1f\n",p*result);
}
