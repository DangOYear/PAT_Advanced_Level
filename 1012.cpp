#include<stdio.h>
#include<algorithm>
#include<map>
#include<utility>
#define MAX_N 2100

using namespace std;


struct Student{
	int id;
	int grade[4];
	int rank[4];
}stu[MAX_N];

map<int,int> p;
int n,m;

int course;
int subject[]={'A','C','M','E'};
bool cmp(struct Student a,struct Student b){
	return a.grade[course]>b.grade[course];
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&stu[i].id);
		for(int j=1;j<=3;j++){
			scanf("%d",&stu[i].grade[j]);
		}
		//p.insert(make_pair(stu[i].id,i));
		stu[i].grade[0]=(double)(stu[i].grade[1]+stu[i].grade[2]+stu[i].grade[3])/3.0+0.5;
		//printf("%d\n",stu[i].grade[0]);
	}
	for(course=0;course<4;course++){
		sort(stu,stu+n,cmp);
		stu[0].rank[course]=1;
		for(int i=1;i<n;i++){
			if(stu[i].grade[course]==stu[i-1].grade[course]){
				stu[i].rank[course]=stu[i-1].rank[course];
			}
			else{
				stu[i].rank[course]=i+1;
			}
		}
	}
	for(int i=0;i<n;i++){
		p[stu[i].id]=i;
	}
	
	int query;
	for(int i=0;i<m;i++){
		scanf("%d",&query);
		if(p.find(query)==p.end()){
			printf("N/A\n");
		}
		else{
			int minpos=0;
			for(int j=0;j<4;j++){
				if(stu[p[query]].rank[j]<stu[p[query]].rank[minpos]){
					minpos=j;
				}
			}
			printf("%d %c\n",stu[p[query]].rank[minpos],subject[minpos]);
		}
	}
}
