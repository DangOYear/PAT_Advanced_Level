#include<iostream>
using namespace std;


bool HashTable[128];


int main(){
	string s1,s2;
	getline(cin,s1);
	getline(cin,s2);
	
	int len1=s1.length();
	int len2=s2.length();
	for(int i=0;i<len1;i++){
		int j;
		char c1,c2;
		c1=s1[i];
		for(j=0;j<len2;j++){
			c2=s2[j];
			if(c1<='z'&&c1>='a')	c1-=32;
			if(c2<='z'&&c2>='a')	c2-=32;
			if(c1==c2)	break;
		}
		if(j==len2&&!HashTable[c1]){
			cout<<c1;
			HashTable[c1]=true;
		}
	}
}
