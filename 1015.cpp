#include<stdio.h>
#include<math.h>

bool isPrime(int n){
	if(n<=1)	return false;
	int sqr=sqrt(n);
	for(int i=2;i<=sqr;i++){
		if(n%i==0)	return false;
	}
	return true;
}

int main(){
	int n,radix;
	while(scanf("%d",&n)!=EOF){
		if(n<0)	break;
		scanf("%d",&radix);
		if(!isPrime(n)){
			printf("No\n");
		}
		else{
			int l=0;
			int d[110];
			do{
				d[l++]=n%radix;
				n/=radix;
			}while(n!=0);
			for(int i=0;i<l;i++){
				n=n*radix+d[i];
			}
			if(isPrime(n))	printf("Yes\n");
			else	printf("No\n");
		}
	}
}
