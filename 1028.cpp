#include<stdio.h>
#include<algorithm>
#include<string.h>
#define MAX_N 100100

using namespace std;

struct Student{
	int id;
	char name[15];
	int grade;
}stu[MAX_N];

bool cmp1(struct Student a,struct Student b){
	return a.id<b.id;
}

bool cmp2(struct Student a,struct Student b){
	if(strcmp(a.name,b.name)!=0)	return strcmp(a.name,b.name)<0;
	return a.id<b.id;
}


bool cmp3(struct Student a,struct Student b){
	if(a.grade!=b.grade)	return a.grade<b.grade;
	else 	return a.id<b.id;
}
int main(){
	int n;
	int choice;
	scanf("%d%d",&n,&choice);
	for(int i=0;i<n;i++){
		scanf("%d %s %d",&stu[i].id,stu[i].name,&stu[i].grade);
	}
	switch(choice){
		case 1:sort(stu,stu+n,cmp1);break;
		case 2:sort(stu,stu+n,cmp2);break;
		case 3:sort(stu,stu+n,cmp3);break;
	}
	for(int i=0;i<n;i++){
		printf("%06d %s%d\n",stu[i].id,stu[i].name,stu[i].grade);
	}
}
