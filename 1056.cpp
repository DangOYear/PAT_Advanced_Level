#include<stdio.h>
#include<queue>

using namespace std;
#define MAX_N 1010

struct mouse{
	int weight;
	int rank;
}mouse[MAX_N];

queue<int >q;

int main(){
	int np,ng,order;
	scanf("%d%d",&np,&ng);
	for(int i=0;i<np;i++){
		scanf("%d",&mouse[i].weight);
	}
	for(int i=0;i<np;i++){
		scanf("%d",&order);
		q.push(order);	
	}
	int num=np;
	int group;
	while(q.size()!=1){
		if(num%ng==0)	group=num/ng;
		else	group=num/ng+1;
		for(int i=0;i<group;i++){
			int max=q.front();
			for(int j=0;j<ng;j++){
				if(i*ng+j>=num)	break;
				int front=q.front();
				if(mouse[front].weight>mouse[max].weight){
					max=front;
				}
				mouse[front].rank=group+1;
				q.pop();
			}
			q.push(max);
		}
		num=group;
	}
	mouse[q.front()].rank=1; 
	for(int i=0;i<np;i++){
		printf("%d",mouse[i].rank);
		if(i!=np-1)	printf(" ");
	}
	return 0;
}
