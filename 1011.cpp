#include<iostream>
#include<iomanip>
using namespace std;

char S[3]={'W','T','L'};



int main(){
	
	
	double num,temp;
	int max_index;
	double ans=1;
	for(int i=0;i<3;i++){
		temp=0;
		for(int j=0;j<3;j++){
			cin>>num;
			if(num>temp){
				temp=num;
				max_index=j;
			}
			
		}
		cout<<S[max_index]<<" ";
		ans*=temp;	
	}
	cout<<fixed<<setprecision(2)<<(ans*0.65-1)*2<<endl;
}
