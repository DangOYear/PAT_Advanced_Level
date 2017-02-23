#include<stdio.h>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>

using namespace std;

#define MAX_N 110

int Map[256];
char s[MAX_N];
vector<char> v;

int main(){
	int k;
	scanf("%d",&k);
	scanf("%s",s);
	//puts(s);
	for(int i=0;i<strlen(s);i++){
		
	}
	for(int i=0;i<256;i++){
		if(Map[i]!=0&&Map[i]%k==0){
			v.push_back(char(i));
		}
	}
	for(int i=0;i<v.size();i++){
		printf("%c ",v[i]);
	}
}

