#include<stdio.h>
#include<vector>
#define MAX_N 10100


int set[MAX_N];

//vector<int> v;

int find(int r){
	int x=r;
	while(set[r]!=r){
		r=set[r];
	}
	
	while(x!=set[x]){
		int z=x;
		x=set[x];
		set[z]=r;
	}
	return r;
}

void Union(int a,int b){
	int fa=find(a);
	int fb=find(b);
	if(fa==fb){
		return ;
	}
	else
		set[fa]=fb;
}


void init(){
	for(int i=0;i<MAX_N;i++){
		set[i]=i;
	}
}

int main(){
	init();
	int n,k,q;
	int b;
	int temp;
	int count=0;
	int num=-1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d",&b);
			if(j==1){
				temp=b;
			}
			if(b>num)	num=b;
			Union(temp,b);
		}
	}
	for(int i=1;i<=num;i++){
		if(set[i]==i){
			count++;
		}
	}
	
	printf("%d %d\n",count,num);
	scanf("%d",&q);
	int bird1,bird2;
	for(int i=0;i<q;i++){
		scanf("%d%d",&bird1,&bird2);
		if(find(bird1)==find(bird2)){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}
}
