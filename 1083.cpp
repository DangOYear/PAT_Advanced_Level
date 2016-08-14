#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

struct Stu{
	string name;
	string ID;
	int grade;
};


int N;
int grade1,grade2;

struct Stu stu[2000];

bool cmp(struct Stu a,struct Stu b){
	return a.grade>b.grade;
}



int main()
{
	cin>>N;
	int count=0;
	for(int i=0;i<N;i++){
		cin>>stu[i].name;
		cin>>stu[i].ID;
		cin>>stu[i].grade;
	}
	cin>>grade1>>grade2;
	sort(stu,stu+N,cmp);
	for(int i=0;i<N;i++){
		if(stu[i].grade>=grade1&&stu[i].grade<=grade2){
			cout<<stu[i].name<<" "<<stu[i].ID<<endl;
			count++;
		}
	}
	if(count==0)
		cout<<"NONE"<<endl;
	
}
