#include<stdio.h>
#include<set>

using namespace std;


#define MAX_N 51

set<int> s[MAX_N];

void cmp(int str1,int str2){
	int totalnum=s[str2].size();
	int sameNum=0;
	for(set<int>::iterator it=s[str1].begin();it!=s[str1].end();it++){
		if(s[str2].find(*it)!=s[str2].end())	sameNum++;
		else	totalnum++;
	}
	printf("%.1lf%%\n",sameNum*100.0/totalnum);
}

int main(){
	int n,m;
	int v;
	int k;
	int str1,str2;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&m);
		for(int j=0;j<m;j++){
			scanf("%d",&v);
			s[i].insert(v);
		}
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d%d",&str1,&str2);
		cmp(str1,str2);
	}
} 
