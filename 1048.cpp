#include<stdio.h>

#define MAX_N 1010

int HashTable[MAX_N];

int main(){
	int N,M;
	int num;
	bool flag=false;
	scanf("%d%d",&N,&M);
	
	for(int i=0;i<N;i++){
		scanf("%d",&num);
		HashTable[num]++;
	}
	for(int i=0;i<=M/2;i++){
		if(HashTable[i]&&HashTable[M-i]){
			if(i==M-i&&HashTable[i]<=1){
				continue;
			}
			flag=true;
			printf("%d %d",i,M-i);
			break;
		}
		
	}
	if(!flag)	printf("No Solution");
}
