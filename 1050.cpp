#include<stdio.h>
#include<string.h>

#define MAX_N 10010



bool HashTable[128];

char s1[MAX_N];
char s2[MAX_N];
int main(){
	gets(s1);
	gets(s2);
	int len1=strlen(s1);
	int len2=strlen(s2);
	for(int i=0;i<len2;i++){
		HashTable[s2[i]]=true;
	}
	for(int i=0;i<len1;i++){
		if(!HashTable[s1[i]])
			printf("%c",s1[i]);
	}
	
	
}
