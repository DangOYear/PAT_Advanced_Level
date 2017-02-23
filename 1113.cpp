#include<stdio.h>
#include<algorithm>

using namespace std;

#define MAX_N 100100

int num[MAX_N];
int n;

int main(){
	scanf("%d",&n);
	int s1=0,s2=0;
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	sort(num,num+n);
	
	int i;
	
	for(i=0;i<n/2;i++){
		s1+=num[i];
	}
	
	for(;i<n;i++){
		s2+=num[i];
	}
	if(n%2==0){
		
		printf("0 %d",s2-s1);
	}
	else{
		printf("1 %d",s2-s1);
	}
}
