#include<stdio.h>


#define MAX_N 100010
int pos[MAX_N];

void swap(int *a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

int main(){
	int N;
	scanf("%d",&N);
	int left=N-1;
	int num;
	for(int i=0;i<N;i++){
		scanf("%d",&num);
		pos[num]=i;
		if(num==i&&num!=0)
			left--;
	}
	
	int p=1;
	int ans=0;
	
	while(left>0){
		if(pos[0]==0){
			while(p<N){
				if(pos[p]!=p){
					swap(&pos[0],&pos[p]);
					ans++;
					break;
				}
				p++;
			}
			
		}
		
		while(pos[0]!=0){
			swap(&pos[0],&pos[pos[0]]);
			ans++;
			left--;
		}
	}
	printf("%d",ans);
}
