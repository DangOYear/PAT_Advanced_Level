#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;

vector<int> v,fac,ans;
int n,k,p;

int maxfacnum=-1;

void init(){
	int i=0;
	int temp=0;
	while(temp<=n){
		v.push_back(temp);
		temp=pow(++i,p);
	}
}



void DFS(int index,int nowK,int sum,int facSum){
	if(nowK==k&&sum==n){
		if(facSum>maxfacnum){
			ans=fac;
			maxfacnum=facSum;
		}
		return ;
	}
	if(sum>n||nowK>k)	return ;
	if(index>=1){
		fac.push_back(index);
		DFS(index,nowK+1,sum+v[index],facSum+index);
		fac.pop_back();
		DFS(index-1,nowK,sum,facSum);
	}
}

int main(){
	scanf("%d%d%d",&n,&k,&p);
	init();
	DFS(v.size()-1,0,0,0);
	if(maxfacnum==-1){
		printf("Impossible");
	}
	else{
		printf("%d = %d^%d",n,ans[0],p);
		for(int i=1;i<ans.size();i++){
			printf(" + %d^%d",ans[i],p);
		}
	}
}
