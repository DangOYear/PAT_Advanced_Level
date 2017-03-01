#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>
#include<map>
#include<string>
using namespace std;

#define MAX_V 220
#define INF 1000000000 



int G[MAX_V][MAX_V];
bool visited[MAX_V];
int happy[MAX_V];
int maxHappy=0;
int maxHappyAvg=0;
int n,m;
vector<int> pre[MAX_V];
vector<int> temp,path; 
string s_name;
int d[MAX_V];
int num;
map<string,int> NameToId;
map<int,string> IdToName;

void Dijkstra(int s){
	fill(d,d+MAX_V,INF);
	d[s]=0;
	for(int i=0;i<n;i++){
		int u=-1,Min=INF;
		for(int j=0;j<n;j++){
			if(!visited[j]&&d[j]<Min){
				u=j;
				Min=d[j];
			}
		} 
		if(u==-1)	return;
		visited[u]=true;
		for(int v=0;v<n;v++){
			if(!visited[v]&&G[u][v]!=INF){
				if(d[u]+G[u][v]<d[v]){
					d[v]=d[u]+G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}
				else{
					if(d[u]+G[u][v]==d[v]){
						pre[v].push_back(u);
					}
				}
			}
		}
	}
}

void DFS(int v){
	if(v==0){
		temp.push_back(v);
		num++;
		int tempH=0;
		for(int i=temp.size()-2;i>=0;i--){
			int vertex=temp[i];
			tempH+=happy[vertex]; 
		}
		double tempHappyAvg=1.0*tempH/(temp.size()-1);
		if(tempH>maxHappy){
			path=temp;
			maxHappy=tempH;
			maxHappyAvg=tempHappyAvg;
			
		} 
		else{
			if(tempH==maxHappy&&tempHappyAvg>maxHappyAvg){
				path=temp;
				maxHappyAvg=tempHappyAvg;
			}
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
	cin>>n>>m>>s_name;
	string city,city1,city2;
	NameToId[s_name]=0;
	IdToName[0]=s_name;
	
	for(int i=1;i<=n-1;i++){
		cin>>city>>happy[i];
		NameToId[city]=i;
		IdToName[i]=city;
	}
	fill(G[0],G[0]+MAX_V*MAX_V,INF);
	for(int i=0;i<m;i++){
		cin>>city1>>city2;
		int u=NameToId[city1],v=NameToId[city2];
		cin>>G[u][v];
		G[v][u]=G[u][v];
	}
	Dijkstra(0);
	int rome=NameToId["ROM"];
	DFS(rome);
	printf("%d %d %d %d\n",num,d[rome],maxHappy,(int)maxHappyAvg);
	for(int i=path.size()-1;i>=0;i--){
		cout<<IdToName[path[i]];
		if(i>0)	cout<<"->"; 
	}
}
