#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

#define MAX_N 600


struct station{
	double price;
	double distance;
}st[MAX_N];

bool cmp(station a,station b){
	return a.distance<b.distance;
}

int main(){
	int n;
	double Cmax,D,Davg;
	scanf("%lf%lf%lf%d",&Cmax,&D,&Davg,&n);
	for(int i=0;i<n;i++){
		scanf("%lf%lf",&st[i].price,&st[i].distance);
	}
	st[n].distance=D;
	st[n].price=0;
	sort(st,st+n,cmp);
	if(st[0].distance!=0){
		printf("The maximum travel distance = 0.00\n");
	}
	else{
		int pos=0;
		double ans=0,tank=0,MAX=Cmax*Davg;
		while(pos<n){
			int stnum=-1;
			double minPrice=1000000000;
			for(int i=pos+1;i<=n&&st[i].distance-st[pos].distance<=MAX;i++){
				if(st[i].price<minPrice){
					minPrice=st[i].price;
					stnum=i;
				}
				if(minPrice<st[pos].price){
					break;
				}
			}
			if(stnum==-1)	break;
			double need=(st[stnum].distance-st[pos].distance)/Davg;
			if(minPrice<st[pos].price){
				if(tank<need){
					ans+=(need-tank)*st[pos].price;
					tank=0;
				}
				else{
					tank-=need;
				}
			}
			else{
				ans+=(Cmax-tank)*st[pos].price;
				tank=Cmax-need;
			}
			pos=stnum;
		}
		if(pos==n){
			printf("%.2f\n",ans);
		}
		else{
			printf("The maximum travel distance = %.2f\n",st[pos].distance+MAX);
		}
	}
}
