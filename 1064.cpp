#include<stdio.h>
#include<algorithm>

using namespace std;

#define MAX_N 1100

int n;

int CBSTree[MAX_N]; 
int in[MAX_N];

int co=1;

void inOrder(int root){
	if(root>n)	return;
	inOrder(root*2);
	CBSTree[root]=in[co++];
	inOrder(root*2+1);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&in[i]);
	}
	sort(in+1,in+1+n);
	inOrder(1);
	for(int i=1;i<=n;i++){
		printf("%d",CBSTree[i]);
		if(i!=n)
			printf(" ");
	} 
}
