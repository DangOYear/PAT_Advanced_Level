//http://codeup.cn/problem.php?id=5644

#include<iostream>
#include<iomanip>
using namespace std;

double a[3];
double b[3];
double c[3];
int max_a=0,max_b=0,max_c=0;

void print(int max_num){
	if(max_num==0)
		cout<<"W"<<" ";
	if(max_num==1)
		cout<<"T"<<" ";
	if(max_num==2)
		cout<<"L"<<" ";
}

int main()
{
	double sum=1;
	for(int i=0;i<3;i++){
		cin>>a[i];
		if(a[i]>a[max_a])	max_a=i;
	}
	for(int i=0;i<3;i++){
		cin>>b[i];
		if(b[i]>b[max_b])	max_b=i;
	}
	for(int i=0;i<3;i++){
		cin>>c[i];
		if(c[i]>c[max_c])	max_c=i;
	}
	print(max_a);
	print(max_b);
	print(max_c);
	if(max_a==0){
		sum*=0.65;
	}
	if(max_b==0){
		sum*=0.65;
	}
	if(max_c==0){
		sum*=0.65;
	}
	cout<<fixed<<setprecision(2)<<(sum*a[max_a]*b[max_b]*c[max_c]-1)*2<<endl;
	
	
}
