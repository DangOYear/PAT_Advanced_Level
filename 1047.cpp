#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>

using namespace std;

#define MAX_N 40010
#define MAX_Course 2510


char name[MAX_N][5];
vector<int> course[MAX_Course];

bool cmp(int a,int b){
	return strcmp(name[a],name[b])<0;
}

int main(){
	int n,k;
	int num;
	int courseID;
	scanf("%d%d",&n,&k);
	 for(int i=0;i<n;i++){
	 	scanf("%s %d",name[i],&num);
	 	for(int j=0;j<num;j++){
	 		scanf("%d",&courseID);
	 		course[courseID].push_back(i);
		 }
	 }
	 for(int i=1;i<=k;i++){
	 	printf("%d %d\n",i,course[i].size());
	 	sort(course[i].begin(),course[i].end(),cmp);
	 	for(int j=0;j<course[i].size();j++){
	 		printf("%s\n",name[course[i][j]]);
		 }
	 }
}
