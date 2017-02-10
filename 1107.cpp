#include<stdio.h>
#include<algorithm>

using namespace std;

#define MAX_N 1100
int set[MAX_N];
int n;
int course[MAX_N];
int root[MAX_N];

int find(int x){
	int r=x;
	while(set[r]!=r){
		r=set[r];
	}
	return r;
}

int merge(int x,int y){
	int fx,fy;
	fx=find(x);
	fy=find(y);
	if(fx==fy)	return 0;
	else{
		set[fx]=fy;
	}
} 

void init(){
	for(int i=1;i<=n;i++){
		set[i]=i;
	}
} 

bool cmp(int a,int b){
	return a>b;
}

int main(){
	scanf("%d",&n);
	init();
	int count=0;
	int k;
	for(int i=1;i<=n;i++){
		scanf("%d:",&k);
		int h;
		for(int j=0;j<k;j++){
			scanf("%d",&h); 
			if(course[h]==0)
				course[h]=i;
			merge(i,find(course[h]));
		}
	}
	for(int i=1;i<=n;i++){
		root[find(i)]++;
	}
	for(int i=1;i<=n;i++){
		if(root[i]!=0)
			count++;
	}
	printf("%d\n",count);
	sort(root+1,root+n+1,cmp);
	for(int i=1;i<=count;i++){
		printf("%d",root[i]);
		if(i!=count)
			printf(" ");
	}
}

