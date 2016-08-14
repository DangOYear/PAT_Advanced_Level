#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;

int minx,maxx;

int cal(int x){
	int a[4];
	a[0]=x%10;
	a[1]=x/10%10;
	a[2]=x/100%10;
	a[3]=x/1000;
	sort(a,a+4);
	minx=a[0]*1000+a[1]*100+a[2]*10+a[3];
	maxx=a[3]*1000+a[2]*100+a[1]*10+a[0];
}


int main()
{
	int N;
	int s;
	scanf("%d",&N);
	if((N%10==N/10%10)&&(N/10%10==N/100%10)&&(N/100%10==N/1000))
		printf("%04d - %04d = 0000",N,N);
	else
		do{
			cal(N);
			s=maxx-minx;
			printf("%04d - %04d = %04d\n",maxx,minx,s);
			N=s;
		}while(s!=6174);
	return 0;
}
