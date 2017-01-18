#include<cstdio>

char radix[13]={'0','1','2','3','4','5','6','7','8','9','A'
				,'B','C'};

int main(){
	int m,n,l;
	scanf("%d%d%d",&m,&n,&l);
	printf("#");
	printf("%c%c",radix[m/13],radix[m%13]);
	printf("%c%c",radix[n/13],radix[n%13]);
	printf("%c%c",radix[l/13],radix[l%13]);
}
