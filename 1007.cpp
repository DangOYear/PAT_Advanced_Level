#include<stdio.h>


#define MAX_N 10100

int num[MAX_N];
int dp[MAX_N];
int s[MAX_N];

int main(){
	int n;
	scanf("%d",&n);
	bool flag=false;
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
		if(num[i]>0)	flag=true;
	}
	if(!flag)	printf("0 %d %d\n",num[0],num[n-1]);
	else{
		dp[0]=num[0];
		for(int i=1;i<n;i++){
			if(dp[i-1]+num[i]>num[i]){
				dp[i]=dp[i-1]+num[i];
				s[i]=s[i-1];
			}
			else{
				dp[i]=num[i];
				s[i]=i;
			}
		}
		int max=0;
		for(int i=0;i<n;i++){
			if(dp[i]>dp[max]){
				max=i;
			}
		}
		printf("%d %d %d",dp[max],num[s[max]],num[max]);
	}
}
