#include<iostream>
#include<string.h>
using namespace std;


char s[101];
char *num[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};

char c[4];

int main()
{
	int sum;
	gets(s);
	for(int i=0;i<strlen(s);i++)
	{
		sum+=s[i]+(0-'0');
	}
	int count=0;
	while(sum){
		c[count]=sum%10;
		count++;
		sum=sum/10;
	}
	printf("%s",num[c[--count]]);
	for(int i=--count;i>=0;i--)	
	{
		printf(" %s",num[c[i]]);
	}
}
