#include<iostream>
using namespace std;

int a[100];

bool judge(int a[],int i){
	for(int j=0;j<=i/2;j++){
		if(a[j]!=a[i-1-j]){
			return false;
		}
	}
	return true;
} 


int main(){
	int m,n;
	
	int i=0;
	bool flag;
	cin>>m>>n;
	if(m==0) i=1;//¿Óµã 
	
	while(m>0){
		a[i]=m%n;
		m=m/n;
		i++;
	}
	/*
	do{
		a[i]=m%n;
		m=m/n;
		i++;
	}while(m!=0);
	*/
	
	flag=judge(a,i);
	if(flag)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	for(int j=i-1;j>=0;j--){
		cout<<a[j];
		if(j!=0)	cout<<" ";
	}	
}
