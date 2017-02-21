#include<stdio.h>
#include<algorithm>

using namespace std;

#define MAX_STU 40100
#define MAX_SCH 110

struct Student{
	int GE;
	int GI;
	int sum;
	int ID;
	int choice[6];
	int rank;
}stu[MAX_STU];

struct School{
	int quota;
	int actNum;
	int id[MAX_STU];
	int lastAdmit;
}sch[MAX_SCH];

int n,m,k;

bool cmpGrade(Student a,Student b){
	if(a.sum!=b.sum)	return a.sum>b.sum;
	else	return a.GE>b.GE;
}

bool cmpID(int a,int b){
	return a<b;
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++){
		scanf("%d",&sch[i].quota);
		sch[i].lastAdmit=-1;
	}
	for(int i=0;i<n;i++){
		stu[i].ID=i;
		scanf("%d%d",&stu[i].GE,&stu[i].GI);
		stu[i].sum=(stu[i].GE+stu[i].GI)/2;
		for(int j=0;j<k;j++){
			scanf("%d",&stu[i].choice[j]);
		}
	}
	sort(stu,stu+n,cmpGrade);
	for(int i=0;i<n;i++){
		if(i>0&&stu[i].sum==stu[i-1].sum&&stu[i].GE==stu[i-1].GE){
			stu[i].rank=stu[i-1].rank;
		}
		else{
			stu[i].rank=i;
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			int cho=stu[i].choice[j];
			int num=sch[cho].actNum;
			int last=sch[cho].lastAdmit;
			if(num<sch[cho].quota||(last!=-1&&stu[i].rank==stu[last].rank)){
				sch[cho].actNum++;
				sch[cho].lastAdmit=i;
				//printf("%d\n",stu[i].ID);
				sch[cho].id[num]=stu[i].ID;
				break;
			}
			
		}
	}
	
	for(int i=0;i<m;i++){
		if(sch[i].actNum>0){
			sort(sch[i].id,sch[i].id+sch[i].actNum,cmpID);
			for(int j=0;j<sch[i].actNum;j++){
				printf("%d",sch[i].id[j]);
				if(j!=sch[i].actNum-1)
					printf(" ");
			}
		}
		printf("\n");
	}
	
}
