#include<iostream>

using namespace std;

#define MAX_N 56
#define N 54

char map[5]={'S','H','C','D','J'};


int start[MAX_N];
int Next[MAX_N];
int End[MAX_N];


int main(){
	int K;
	cin>>K;
	
	for(int i=1;i<=N;i++){
		start[i]=i;
	}
	for(int i=1;i<=N;i++){
		cin>>Next[i];
	}
	for(int i=0;i<K;i++){
		for(int j=1;j<=N;j++){
			End[Next[j]]=start[j];
		}
		
		for(int j=1;j<=N;j++){
			start[j]=End[j];
		}
	}
	
	for(int i=1;i<=N;i++){
		if(i!=1)	cout<<" ";
		cout<<map[(start[i]-1)/13]<<(start[i]-1)%13+1;
	}
	
}
