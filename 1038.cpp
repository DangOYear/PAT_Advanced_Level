#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;


#define MAX_N 10010

string s[MAX_N];

bool cmp(string a,string b){
	return a+b<b+a;
}

int main(){
	int N;
	string res;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>s[i];
	}
	sort(s,s+N,cmp);
	for(int i=0;i<N;i++){
		res+=s[i];
	}
	while(res.size()!=0&&res[0]=='0'){
		res.erase(res.begin());
	}
	if(res.size()==0)	cout<<"0"<<endl;
	else	cout<<res<<endl;
}
