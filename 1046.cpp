


#include<iostream>
#include<algorithm>

using namespace std;

#define MAX_N 100005


int dis[MAX_N];
int A[MAX_N];


int main(){
	int sum=0;
	
	int N;
	int M;
	int left,right;
	int temp;
	cin>>N;
	
	for(int i=1;i<=N;i++){
		cin>>A[i];
		sum+=A[i];
		dis[i]=sum;
	}
	cin>>M;
	for(int i=0;i<M;i++){
		cin>>left>>right;
		if(left>right){
			temp=left;
			left=right;
			right=temp;
		}
		
		temp=dis[right-1]-dis[left-1];
		cout<<min(temp,sum-temp)<<endl;
	}
	
	
}

