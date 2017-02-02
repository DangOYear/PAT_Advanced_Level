#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

#define MAX_N 40010
#define MAX_M (26*26*26*10+1)

vector<int >sel[MAX_M]; 


int getID(char name[]){
	int id=0;
	for(int i=0;i<3;i++){
		id=id*26+(name[i]-'A');
	}
	id=id*10+name[3]-'0';
	return id;
}

int main(){
	int n,k;
	char name[5];
	scanf("%d%d",&n,&k);
	for(int i=0;i<k;i++){
		int course,num,id;
		scanf("%d%d",&course,&num);
		for(int j=0;j<num;j++){
			scanf("%s",name);
			id=getID(name);
			sel[id].push_back(course);
		}
		
	}
	for(int i=0;i<n;i++){
		scanf("%s",name);
		int id=getID(name);
		sort(sel[id].begin(),sel[id].end()); 
		printf("%s %d",name,sel[id].size());
		for(int j=0;j<sel[id].size();j++){
			printf(" %d",sel[id][j]);
		}
		printf("\n");
	}
}
