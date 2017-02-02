#include<stdio.h>
#include<math.h>

#define MAX_N 11111

bool hashtable[MAX_N];

bool is_Prime(int n){
	if(n<=1)	return false;
	int sqr=(int)sqrt(1.0*n);
	for(int i=2;i<=sqr;i++){
		if(n%i==0)	return false;
	}
	return true;
}



int main(){
	int n,msize,a;
	scanf("%d%d",&msize,&n);
	while(!is_Prime(msize)){
		msize++;
	}
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		int pos=a%msize;
		if(!hashtable[pos]){
			hashtable[pos]=true;
			if(i==0)	printf("%d",pos);
			else	printf(" %d",pos);
		}
		else{
			int step;
			for(step=1;step<msize;step++){
				pos=(a+step*step)%msize;
				if(!hashtable[pos]){
					hashtable[pos]=true;
					if(i==0)	printf("%d",pos);
					else	printf(" %d",pos);
					break;
				}
			}
			if(step>=msize){
				if(i>0)	printf(" ");
				printf("-");
			}
		}
		
	}
}
