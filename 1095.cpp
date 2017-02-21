#include<stdio.h>
#include<algorithm>
#include<string>
#include<string.h>
#include<map>
#define MAX_N 10100


using namespace std;

struct Car{
	char id[10];
	int time;
	char status[4];
}car[MAX_N],valid[MAX_N]; 

int validnum=0;
map<string,int> parkTime;

int timetransfer(int h,int m,int s){
	return h*3600+m*60+s;
}

bool cmpByIdandTime(Car a,Car b){
	int s=strcmp(a.id,b.id);
	if(s!=0)	return s<0;
	else	return a.time<b.time;
}

bool cmpByTime(Car a,Car b){
	return a.time<b.time;
}

int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	int h,m,s;
	for(int i=0;i<n;i++){
		scanf("%s %d:%d:%d %s",car[i].id,&h,&m,&s,car[i].status);
		car[i].time=timetransfer(h,m,s);
	}
	
	//for(int i=0;i<n;i++){
	//	printf("%s %d %s\n",car[i].id,car[i].time,car[i].status);
		//car[i].time=timetransfer(h,m,s);
	//}
	sort(car,car+n,cmpByIdandTime);
	int maxTime=-1;
	for(int i=0;i<n-1;i++){
		if(strcmp(car[i].id,car[i+1].id)==0&&strcmp(car[i].status,"in")==0&&strcmp(car[i+1].status,"out")==0){
			valid[validnum++]=car[i];
			valid[validnum++]=car[i+1];
			int time=car[i+1].time-car[i].time;
			if(parkTime.find(car[i].id)==parkTime.end()){
				parkTime[car[i].id]=0;
			}
			parkTime[car[i].id]+=time;
			maxTime=max(maxTime,parkTime[car[i].id]);
		}
	}
	sort(valid,valid+validnum,cmpByTime);
	int cursor=0;
	int currentCar=0;
	for(int i=0;i<k;i++){
		scanf("%d:%d:%d",&h,&m,&s);
		int time=timetransfer(h,m,s);
		while(cursor<validnum&&valid[cursor].time<=time){
			if(strcmp(valid[cursor].status,"in")==0){
				currentCar++;
			}
			else{
				currentCar--;
			}
			cursor++;
		}
		printf("%d\n",currentCar);
	}

	for(map<string,int> ::iterator it=parkTime.begin();it!=parkTime.end();it++){
		if(it->second==maxTime){
			printf("%s ",it->first.c_str());
		}
	}
	printf("%02d:%02d:%02d\n",maxTime/3600,maxTime%3600/60,maxTime%60);
}
