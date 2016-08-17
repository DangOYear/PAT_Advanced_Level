#include<iostream>
#include<iomanip>
using namespace std;


#define MAX_N 1011

double p[MAX_N];


int main(){
	int k;
	double a;
	int n;
	int count=0;
	cin>>k;
	while(k--){
		cin>>n>>a;
		p[n]+=a;
	}
	
	cin>>k;
	while(k--){
		cin>>n>>a;
		p[n]+=a;
	}
	
	for(int i=0;i<MAX_N;i++){
		if(p[i]!=0)	count++;
	}
	
	cout<<count;
	for(int i=MAX_N-1;i>=0;i--){
		if(p[i]!=0)	{
			cout<<" "<<i<<" ";
			cout<<fixed<<setprecision(1)<<p[i];
		}
	}
	
}
