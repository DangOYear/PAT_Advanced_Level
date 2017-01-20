#include<stdio.h>

int HashTable[10010];
int a[100010];

int main(){
	int N;
	int count=0;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&a[i]);
		HashTable[a[i]]++;
	}
	
	for(int i=0;i<N;i++){
		if(HashTable[a[i]]==1)
		{
			printf("%d",a[i]);
			count++;
			break;
		}
	}
	if(count==0)	printf("None\n");
	return 0;
}
