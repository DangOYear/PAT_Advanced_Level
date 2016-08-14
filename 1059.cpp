#include<iostream>
#include<math.h>

using namespace std;

#define MAX_N 100010


struct factor{
	int x;
	int cnt;
}fact[10];

bool is_prime(int n){
	if(n==1)	return false;
	int sqr=(int)sqrt(n);
	
	for(int i=2;i<=sqr;i++){
		if(n%i==0)	return false;
	}
	return true;
	
}

int prime[MAX_N];
int pNum=0;

void prime_Table(){
	
	for(int i=1;i<MAX_N;i++){
		if(is_prime(i)){
			prime[pNum++]=i;
		}
	}
}



int main(){
	prime_Table();
	
	int n;
	int num=0;
	cin>>n;
	if(n==1)
		cout<<"1=1";
	else{
		cout<<n<<"=";
		int sqr=(int)sqrt(n);
		for(int i=0;i<pNum&&prime[i]<=sqr;i++){
			if(n%prime[i]==0){
				fact[num].x=prime[i];
				fact[num].cnt=0;
				while(n%prime[i]==0){
					fact[num].cnt++;
					n/=prime[i];
				}
				num++;
			}
			if(n==1)	break;
		}
		
		if(n!=1)	{
			fact[num].x=n;
			fact[num++].cnt=1;
		}
		
		for(int i=0;i<num;i++){
			if(i>0)	cout<<"*";
			cout<<fact[i].x;
			if(fact[i].cnt>1){
				cout<<"^"<<fact[i].cnt;
			}
		}
	}
	
	
	
	
}

