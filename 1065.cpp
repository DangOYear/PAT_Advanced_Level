#include<iostream>
using namespace std;



int main(){
	long long A,B,C;
	long long result;
	int T;
	bool flag=true;
	cin>>T;
	
	for(int i=1;i<=T;i++){
		cin>>A>>B>>C;
		result=A+B;
		
		if(A>0&&B>0&&result<0)	flag=true;
		else	if(A<0&&B<0&&result>=0)	flag=false;
		else	if(result>C)	flag=true;
		else	flag=false;
		if(flag){
			cout<<"Case #"<<i<<": true"<<endl;
		}
		else{
			cout<<"Case #"<<i<<": false"<<endl;
		}
	}
	
}
