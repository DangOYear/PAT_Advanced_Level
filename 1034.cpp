#include<stdio.h>
#include<map>
#include<string.h>
#include<iostream>

using namespace std;

const int MAX_N=2100;

int personNum=0;

map<string,int> NametoId;
map<int,string> IdtoName;
map<string,int> Gang;

int weight[MAX_N];
int G[MAX_N][MAX_N];
bool visited[MAX_N];

int change(string s){
	if(NametoId.find(s)!=NametoId.end()){
		return NametoId[s];
	}
	else{
		NametoId[s]=personNum;
		IdtoName[personNum]=s;
		return personNum++;
	}
}


void dfs(int now,int &head,int &memberNum,int &totalweight){
	memberNum++;
	visited[now]=true;
	if(weight[now]>weight[head]){
		head=now;
	}
	for(int i=0;i<personNum;i++){
		if(G[now][i]>0){
			totalweight+=G[now][i];
			G[now][i]=G[i][now]=0;
			if(!visited[i]){
				dfs(i,head,memberNum,totalweight);
			}
		}
	}
}

int main(){
	int n,K;
	string a,b;
	int w;
	cin>>n>>K;
	for(int i=0;i<n;i++){
		cin>>a>>b>>w;
		int id1=change(a);
		int id2=change(b);
		weight[id1]+=w;
		weight[id2]+=w;
		G[id1][id2]+=w;
		G[id2][id1]+=w;
	}
	
	for(int i=0;i<personNum;i++){
		if(!visited[i]){
			int head=i,memberNum=0,totalweight=0;
			dfs(i,head,memberNum,totalweight);
			if(totalweight>K&&memberNum>2){
				Gang[IdtoName[head]]=memberNum;
			}
		}
	}
	cout<<Gang.size()<<endl;
	for(map<string,int>::iterator it=Gang.begin();it!=Gang.end();it++){
		cout<<it->first<<" "<<it->second<<endl;
	}
}
