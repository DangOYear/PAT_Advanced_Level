#include<iostream>
#include<string>
using namespace std;

struct people{
	string name;
	string passwd;
	bool ischange;
}p[1010]; 


void replace(struct people &a,int &cnt){
	for(int i=0;i<a.passwd.length();i++){
		if(a.passwd[i]=='1'){
			a.passwd[i]='@';
			a.ischange=true;
		}
		if(a.passwd[i]=='0'){
			a.passwd[i]='%';
			a.ischange=true;
		}
		if(a.passwd[i]=='l'){
			a.passwd[i]='L';
			a.ischange=true;
		}
		if(a.passwd[i]=='O'){
			a.passwd[i]='o';
			a.ischange=true;
		}
	}
	if(a.ischange)	cnt++;
}

int main(){
	int N;
	int count=0;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>p[i].name>>p[i].passwd;
		p[i].ischange=false;
	}
	for(int i=0;i<N;i++){
		replace(p[i],count);
	}
	if(count==0){
		if(N==1){
			cout<<"There is 1 account and no account is modified"<<endl;
		}
		else{
			cout<<"There is "<<N<<" accounts and no account is modified"<<endl;
		}
	}
	else{
		cout<<count<<endl;
		for(int i=0;i<N;i++){
			if(p[i].ischange){
				cout<<p[i].name<<" "<<p[i].passwd<<endl;
			}
		}
	}
}
