#include<stdio.h>
#include<string.h>

char str[90];
char res[50][50];


int main(){
	int n,n1,n2;
	int l;
	for(int i=0;i<50;i++){
		for(int j=0;j<50;j++){
			res[i][j]=' ';
		}
	}
	gets(str);
	l=strlen(str);
//	printf("%d\n",l);
	n1=(l+2)/3;
	n2=n1;
	n=l+2-n1-n2;
	
	int k=0;//str
	
	for(int i=0;i<n1;i++){
		res[i][0]=str[k++];
	}
	
	for(int j=1;j<n-1;j++){
		res[n1-1][j]=str[k++];
	}
	
	for(int j=n1-1;j>=0;j--){
		res[j][n-1]=str[k++];
	}
	
	for(int i=0;i<n1;i++){
		for(int j=0;j<n;j++){
			printf("%c",res[i][j]);
		}
		printf("\n");
	}
	return 0;
}

