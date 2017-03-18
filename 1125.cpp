#include<stdio.h>
#include<algorithm>

using namespace std;

#define MAX_N 10100


int main(){
	int n;
	double a[MAX_N];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lf",&a[i]);
	}
	sort(a,a+n);
	double ans=a[0];
	for(int i=1;i<n;i++){
		ans=(ans+a[i])/2;
	}
	printf("%d",(int)ans);
}
