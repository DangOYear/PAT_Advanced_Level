#include<stdio.h>
#include<map>

using namespace std;



int main(){
	int n,m,color;
	map<int,int > p;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&color);
			if(p.find(color)!=p.end())	p[color]++;
			else	p[color]=1;
		}
	}
	int key=0;
	int max=0;
	for(map<int,int>::iterator it=p.begin();it!=p.end();it++){
		if(it->second>max){
			key=it->first;
			max=it->second;
		}
	}
	printf("%d",key);
}
