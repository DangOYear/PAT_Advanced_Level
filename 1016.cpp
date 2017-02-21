#include<stdio.h>
#include<algorithm>
#include<string.h>

using namespace std;

#define MAX_N 1100


struct Record{
	char name[25];
	int month,d,h,m;
	bool status;
}r[MAX_N],temp;

int toll[25];

int n;

bool cmp(Record a,Record b){
	int m=strcmp(a.name,b.name);
	if(m!=0)	return m<0;
	else if(a.month!=b.month)	return a.month<b.month;
	else if(a.d!=b.d)	return a.d<b.d;
	else if(a.h!=b.h)	return a.h<b.h;
	else	return a.m<b.m;
}

void get_time_money(int left,int right,int &time,int &money){
	temp=r[left];
	while(temp.d<r[right].d||temp.h<r[right].h||temp.m<r[right].m){
		time++;
		money+=toll[temp.h];
		temp.m++;
		if(temp.m>=60){
			temp.m=0;
			temp.h++;
		}
		if(temp.h>=24){
			temp.h=0;
			temp.d++;
		}
	}
}

int main(){
	char sta[16];
	for(int i=0;i<24;i++){
		scanf("%d",&toll[i]);
	}
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s %d:%d:%d:%d",r[i].name,&r[i].month,&r[i].d,&r[i].h,&r[i].m);
		scanf("%s",sta);
		if(strcmp(sta,"on-line")==0){
			r[i].status=true;
		}
		else{
			r[i].status=false;
		}
	}
	
	sort(r,r+n,cmp);
	int pair_first=0,pair_second,next;
	while(pair_first<n){
		int isNeedPrint=0;
		next=pair_first;
		while(next<n&&strcmp(r[pair_first].name,r[next].name)==0){
			if(isNeedPrint==0&&r[next].status==true){
				isNeedPrint=1;
			}
			else if(isNeedPrint==1&&r[next].status==false){
				isNeedPrint=2;
			}
			next++;
		}
		if(isNeedPrint<2){
			pair_first=next;
			continue;
		}
		int SumOfMoney=0;
		printf("%s %02d\n",r[pair_first].name,r[pair_first].month);
		while(pair_first<next){
			while(pair_first<next-1&&!(r[pair_first].status==true&&r[pair_first+1].status==false)){
				pair_first++;
			}
			pair_second=pair_first+1;
			
			if(pair_second==next){
				pair_first=next;
				break;
			}
			printf("%02d:%02d:%02d ",r[pair_first].d,r[pair_first].h,r[pair_first].m);
			printf("%02d:%02d:%02d ",r[pair_second].d,r[pair_second].h,r[pair_second].m);
			int time=0,money=0;
			get_time_money(pair_first,pair_second,time,money);
			SumOfMoney+=money;
			printf("%d $%.2f\n",time,money/100.0);
			pair_first=pair_second+1;
		}
		printf("Total amount: $%.2f\n",SumOfMoney/100.0);
	}
	
}
