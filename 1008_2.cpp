#include<iostream>
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
	
}
