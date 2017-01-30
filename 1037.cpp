#include<stdio.h>
#include<algorithm>

#define MAX_N 100010
int coupon[MAX_N];
int product[MAX_N];

int main(){
	int n,m;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&coupon[i]);
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d",&product[i]);
	}
	std::sort(coupon,coupon+n);
	std::sort(product,product+m);
	int i=0,j,ans=0;
	while(i<n&&i<m&&coupon[i]<0&&product[i]<0){
		ans+=product[i]*coupon[i];
		i++;
	}
	i=n-1;
	j=m-1;
	while(i>=0&&j>=0&&coupon[i]>0&&product[j]>0){
		ans+=product[j]*coupon[i];
		i--;j--;
	}
	printf("%d\n",ans);
	return 0;
}
