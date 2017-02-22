#include<stdio.h>
#include<set>


using namespace std;

set<int> s;

int solve(int num){
	int sum=0;
	while(num>0){
		sum+=(num%10);
		num/=10;
	}
	return sum;
}

int main(){
	int n;
	int num;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&num);
		num=solve(num);
		s.insert(num);
	}
	printf("%d\n",s.size());
	for(set<int>::iterator it=s.begin();it!=s.end();it++){
		if(it==s.begin())	printf("%d",*it);
		else	printf(" %d",*it);
	}
}
