#include<stdio.h>
#include<string.h>


#define MAX_N 1100

int k;
char str[MAX_N];

bool map[256];
bool visited[256];

int main(){
	scanf("%d",&k);
	scanf("%s",str);
	int count=1;
	int len=strlen(str);
	//if(len==1)	map[str[0]]=true;
	//if(len>1&&str[1]!=str[0])	map[str[0]]=true;
	
	for(int i=1;i<=len;i++){
		if(str[i]==str[i-1]){
			count++;
		}
		if(str[i]!=str[i-1]){
			if(count%k!=0){
				map[str[i-1]]=true;
			}
			count=1;
		}
	}
	for(int i=0;i<len;i++){
		if(map[str[i]]==false&&!visited[str[i]]){
			visited[str[i]]=true;
			printf("%c",str[i]);
			i=i+k-1;
		}
	}
	printf("\n");
	for(int i=0;i<len;i++){
		printf("%c",str[i]);
		if(map[str[i]]==false){
			i=i+k-1;
		}
	}
}
