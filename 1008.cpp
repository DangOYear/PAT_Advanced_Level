#include<iostream>
using namespace std;

#define MAX_N 110


int main(){
	int N;
	int a[MAX_N];
	int sum=0;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>a[i];
	}
	
	sum+=a[0]*6+5;
	for(int i=0;i<N-1;i++){
		if(a[i+1]>=a[i])	sum+=(a[i+1]-a[i])*6+5;
		if(a[i+1]<a[i])		sum+=(a[i]-a[i+1])*4+5;
	}
	cout<<sum<<endl;
	
}
/*#include<iostream>
using namespace std;

int main(){
	int N;
	cin>>N;
	int start=0;
	int end=0;
	int time=0;
	for(int i=0;i<N;i++){
		cin>>end;
		if(end>=start)	time+=(end-start)*6+5;
		else			time+=(start-end)*4+5;
		
		start=end;
	}
	cout<<time<<endl;
	
}*/
