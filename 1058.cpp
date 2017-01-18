#include<cstdio>


int main(){
	int A[3],B[3],C[3];
	int carry;
	scanf("%d.%d.%d",&A[0],&A[1],&A[2]);
	scanf("%d.%d.%d",&B[0],&B[1],&B[2]);
	C[2]=(A[2]+B[2])%29;
	carry=(A[2]+B[2])/29;
	
	C[1]=(A[1]+B[1]+carry)%17;
	carry=(A[1]+B[1]+carry)/17;
	
	C[0]=(A[0]+B[0]+carry);
	
	printf("%d.%d.%d",C[0],C[1],C[2]);
}
