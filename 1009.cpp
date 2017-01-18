#include<iostream>
#include<iomanip>
using namespace std;

struct Poly{
	int exp;
	double coe;
}poly[1010];

double ans[2020];

int main(){
	int m,n;
	int count=0;
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>poly[i].exp>>poly[i].coe;
	} 
	cin>>n;
	for(int i=0;i<n;i++){
		int exp;
		double coe;
		cin>>exp>>coe;
		for(int j=0;j<m;j++){
			ans[exp+poly[j].exp]+=coe*poly[j].coe;
		}
	}
	for(int i=0;i<2020;i++){
		if(ans[i]!=0.0)	count++; 
	}
	
	cout<<count;
	for(int i=2020;i>=0;i--){
		if(ans[i]!=0.0){ 
			cout<<" "<<i<<" ";
			cout<<fixed<<setprecision(1)<<ans[i];
		} 
	}
}

