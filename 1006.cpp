#include<stdio.h>

struct P{
	char id[20];
	int hour,minute,second;
}temp,ear,late;

//temp

bool cmp(struct P a,struct P b){
	if(a.hour!=b.hour)	return a.hour>=b.hour;
	if(a.minute!=b.minute)	return a.minute>=b.minute;
	return a.second>=b.second;
}

void init(){
	ear.hour=24;
	ear.minute=60;
	ear.second=60;
	
	late.hour=0;
	late.minute=0;
	late.second=0;
}


int main(){
	init();
	int M;
	scanf("%d",&M);
	for(int i=0;i<M;i++){
		scanf("%s%d:%d:%d",temp.id,&temp.hour,&temp.minute,&temp.second);
		if(cmp(ear,temp))	ear=temp;
		scanf("%d:%d:%d",&temp.hour,&temp.minute,&temp.second);
		if(cmp(temp,late))	late=temp;
		
	}
	
	printf("%s %s",ear.id,late.id);
}
