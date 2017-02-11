#include<stdio.h>
#include<string.h>
#include<algorithm>

#define MAX_N 10100

using namespace std;

struct Student{
	int id;
	int score[6];
	bool flag;
	int score_sum;
	int prefectsolve;
	int rank;
	Student(){
		for(int i=1;i<=5;i++){
			score[i]=-1;
		}
		flag=false;
		score_sum=0;
		prefectsolve=0;
		rank=0;
	}
}stu[MAX_N];

bool cmp(struct Student a,struct Student b){
	if(a.flag!=b.flag)	return a.flag>b.flag;
	else if(a.score_sum!=b.score_sum)	return a.score_sum>b.score_sum;
	else if(a.prefectsolve!=b.prefectsolve)	return a.prefectsolve>b.prefectsolve;
	return a.id<b.id;
}

int n,k,m;

int full[6];
int main(){
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1;i<=n;i++){
		stu[i].id=i;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&full[i]);
	}
	int user_id,pat_id,pat_score;
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&user_id,&pat_id,&pat_score);
		if(pat_score!=-1){
			stu[user_id].flag=true;
		}
		if(pat_score==-1&&stu[user_id].score[pat_id]==-1){
			stu[user_id].score[pat_id]=0;
		}
		if(pat_score==full[pat_id]&&stu[user_id].score[pat_id]<full[pat_id]){
			stu[user_id].prefectsolve++;
		}
		if(pat_score>stu[user_id].score[pat_id]){
			stu[user_id].score[pat_id]=pat_score;
		}	
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(stu[i].score[j]!=-1){
				stu[i].score_sum+=stu[i].score[j];
			}
		}
	}
	
	sort(stu+1,stu+n+1,cmp);
	
	stu[1].rank=1;
	
	for(int i=1;i<=n;i++){
		if(!stu[i].flag){
			break;
		}
	//	if(i>=2&&stu[i].score_sum!=stu[i-1].score_sum){
	//		stu[i].rank=i;
	//	}
	//	else if(i>=2){
	//		stu[i].rank=stu[i-1].rank;
	//	}
		
		if(i>=2){
			if(stu[i].score_sum!=stu[i-1].score_sum){
				stu[i].rank=i;
			}
			else
				stu[i].rank=stu[i-1].rank;
		} 
		
		
		printf("%d %05d %d",stu[i].rank,stu[i].id,stu[i].score_sum);
		for(int j=1;j<=k;j++){
			if(stu[i].score[j]==-1){
				printf(" -");
			}
			else{
				printf(" %d",stu[i].score[j]);
			}
		}
		printf("\n");
	}
	
}
