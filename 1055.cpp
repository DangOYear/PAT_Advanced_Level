#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>

using namespace std;

#define MAX_N 100100


struct Person{
	char name[10];
	int age;
	int wealth;
}p[MAX_N],valid[MAX_N];

int n,k;
int age[MAX_N];

bool cmp(struct Person a,struct Person b){
	if(a.wealth!=b.wealth)	return a.wealth>b.wealth;
	if(a.age!=b.age)	return a.age<b.age;
	return strcmp(a.name,b.name)<0;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%s %d%d",p[i].name,&p[i].age,&p[i].wealth);
	}
	
	sort(p,p+n,cmp);
	int num=0;
	for(int i=0;i<n;i++){
		if(age[p[i].age]<100){
			age[p[i].age]++;
			valid[num++]=p[i];
		}
	}
	
	int m,amin,amax;
	
	for(int i=1;i<=k;i++){
		scanf("%d%d%d",&m,&amin,&amax);
		printf("Case #%d:\n",i);
		int count=0;
		for(int j=0;j<num&&count<m;j++){
			if(valid[j].age>=amin&&valid[j].age<=amax){
				printf("%s %d %d\n",valid[j].name,valid[j].age,valid[j].wealth);
				count++;
			}
			
		}
		if(count==0){
			printf("None\n");
		}
	}
}
