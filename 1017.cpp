#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

#define MAX_N 110
#define INF 1000000000


struct Customer{
	int arriveTime;
	int processingTime;
}customer;

int endTime[MAX_N];
vector<Customer> c;

int TimeToSecond(int h,int m,int s){
	return h*3600+m*60+s;
}

bool cmp(struct Customer a,struct Customer b){
	return a.arriveTime<b.arriveTime;
}

int main(){
	int n,k,totaltime=0;
	int start=TimeToSecond(8,0,0);
	int stop=TimeToSecond(17,0,0);
	scanf("%d%d",&n,&k);
	for(int i=0;i<k;i++)	endTime[i]=start;
	
	int h,m,s,processingTime;
	for(int i=0;i<n;i++){
		scanf("%d:%d:%d %d",&h,&m,&s,&processingTime);
		int arriveTime=TimeToSecond(h,m,s);
		if(arriveTime>stop)	continue;
		customer.arriveTime=arriveTime;
		if(processingTime>60)	processingTime=60;
		customer.processingTime=processingTime*60;
		c.push_back(customer);
	}
	sort(c.begin(),c.end(),cmp);
	for(int i=0;i<c.size();i++){
		int index=-1,minEndTime=INF;
		for(int j=0;j<k;j++){
			if(endTime[j]<minEndTime){
				minEndTime=endTime[j];
				index=j;
			}		
		}
		if(endTime[index]<c[i].arriveTime){
			endTime[index]=c[i].arriveTime+c[i].processingTime;
		}
		else{
			totaltime+=(endTime[index]-c[i].arriveTime);
			endTime[index]+=c[i].processingTime;
		}
	}
	if(c.size()==0)	printf("0.0");
	else	printf("%.1f",totaltime/60.0/c.size());
	
}

