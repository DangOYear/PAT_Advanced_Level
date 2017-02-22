#include<stdio.h>
#include<vector>

#define MAX_N 100100

using namespace std;

struct Node{
	int s;
	int e;
}node;

vector<Node> v;

int d[MAX_N];
int n,m;
int Min=0;

void solve(){
	int res=Min;
	int s=1,t=1,sum=0;
	for(;;){
		while(t<=n&&sum<m){
			sum+=d[t++];
		}
		if(sum<m)	break;
		
		if(sum>=m){
			if(sum<res){
				res=sum;
				v.clear();
				node.s=s;
				node.e=t-1;
				v.push_back(node);
			}
			else if(sum==res){
					node.s=s;
					node.e=t-1;
					v.push_back(node);
			}
			sum-=d[s++];
		}
	}
}

int main(){
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&d[i]);
		Min+=d[i];
	}
	solve();
	for(int i=0;i<v.size();i++){
		printf("%d-%d\n",v[i].s,v[i].e);
	}
}
