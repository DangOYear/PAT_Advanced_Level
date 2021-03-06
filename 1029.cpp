#include<stdio.h>


#define INF 0x7ffffff
#define MAX_N 1000010

int s1[MAX_N];
int s2[MAX_N];

int main(){
	int n,m;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&s1[i]);
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d",&s2[i]);
	}
	s1[n]=INF;
	s2[m]=INF;
	int mid=(n+m-1)/2;
	int i=0,j=0,count=0;
	while(count<mid){
		if(s1[i]<s2[j])	i++;
		else	j++;
		count++;
	}
	if(s1[i]<s2[j]){
		printf("%d\n",s1[i]);
	}
	else{
		printf("%d\n",s2[j]);
	}
}
