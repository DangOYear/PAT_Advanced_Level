#include<stdio.h>
#include<algorithm>

#define MAX_N 100100

using namespace std;

int sum[MAX_N];
int n,m,nearm;

int main(){
	scanf("%d%d",&n,&m);
	sum[0]=0;
	int num;
	for(int i=1;i<=n;i++){
		scanf("%d",&num);
		sum[i]=sum[i-1]+num;
	}
	for(int i=1;i<=n;i++){
		int *j=upper_bound(sum+1,sum+n+1,sum[i-1]+m);
		int k=j-sum;
		if(sum[k-1]-sum[i-1]==m){
			nearm=m;
			break;
		}
		else if(k<=n&&sum[k]-sum[i-1]<nearm){
			nearm=sum[k]-sum[i-1];
		}
	}
	for(int i=1;i<=n;i++){
		int *j=upper_bound(sum+1,sum+n+1,sum[i-1]+nearm);
		int k=j-sum;
		if(sum[k-1]-sum[i-1]==nearm){
			printf("%d-%d\n",i,k-1);
		}
	}
}
