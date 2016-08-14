/*
	20160718
	Yu
*/

#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

#define MAX_N 30010

struct Student{
	char registration_number[14];
	int score;
	int final_rank;
	int location_number;
	int local_rank;
};

struct Student Stu[MAX_N];

bool cmp(struct Student a,struct Student b){
	if(a.score!=b.score)	return a.score>b.score;
	else return strcmp(a.registration_number,b.registration_number)<0;
}

int main(){
	int T;
	int N;
	int StuCur=0;
	int StuNum=0;
	cin>>T;
	for(int k=1;k<=T;k++){
		cin>>N;
		for(int i=0;i<N;i++){
			cin>>Stu[StuNum].registration_number;
			cin>>Stu[StuNum].score;
			Stu[StuNum].location_number=k;
			StuNum++;
		}
		
		sort(Stu+StuNum-N,Stu+StuNum,cmp);
		
		Stu[StuNum-N].local_rank=1;
		
		for(int j=StuNum-N+1;j<StuNum;j++){
			if(Stu[j].score==Stu[j-1].score)
				Stu[j].local_rank=Stu[j-1].local_rank;
			else
				Stu[j].local_rank=j+1-(StuNum-N);
		}	
	/*	
		for(int j=StuNum-N;j<StuNum;j++){
			cout<<Stu[j].registration_number<<" "<<Stu[j].local_rank<<endl;
		}
	*/
	}
	
	sort(Stu,Stu+StuNum,cmp);
	Stu[0].final_rank=1;
	for(int j=1;j<StuNum;j++){
		if(Stu[j].score==Stu[j-1].score)
			Stu[j].final_rank=Stu[j-1].final_rank;
		else
			Stu[j].final_rank=j+1;
	}	
	
	
	
	cout<<StuNum<<endl;
	for(int i=0;i<StuNum;i++){
		cout<<Stu[i].registration_number<<" "<<
		Stu[i].final_rank<<" "<<Stu[i].location_number
		<<" "<<Stu[i].local_rank<<endl;
	}
	
	
}
