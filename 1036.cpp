#include<iostream>
#include<math.h>
using namespace std;

struct Student{
	char name[20];
	char sex;
	char id[20];
	int score;
}boy,girl,temp;

void init(){
	boy.score=101;
	girl.score=-1;
}

int main(){
	init();
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>temp.name>>temp.sex>>temp.id>>temp.score;
		if(temp.sex=='M'&&temp.score<=boy.score)	boy=temp;
		if(temp.sex=='F'&&temp.score>=girl.score)	girl=temp;
	}
	if(girl.score==-1){
		cout<<"Absent"<<endl;
	}
	else{
		cout<<girl.name<<" "<<girl.id<<endl;
	}
	if(boy.score==101){
		cout<<"Absent"<<endl;
	}
	else{
		cout<<boy.name<<" "<<boy.id<<endl;
	}
	if(girl.score==-1||boy.score==101){
		cout<<"NA"<<endl;
	}
	else{
		cout<<girl.score-boy.score<<endl;
	}
}
