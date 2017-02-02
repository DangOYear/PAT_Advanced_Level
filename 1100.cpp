#include<stdio.h>
#include<iostream>
#include<map>
#include<string>

#define MAX_N 180

using namespace std;

string unit[13]={"tret","jan","feb","mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string decade[13]={"tret","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

string NumToStr[MAX_N];
map<string,int > StrToNum;

void init(){
	for(int i=0;i<13;i++){
		NumToStr[i]=unit[i];
		StrToNum[unit[i]]=i;
		NumToStr[i*13]=decade[i];
		StrToNum[decade[i]]=i*13;
	}
	for(int i=1;i<13;i++){
		for(int j=1;j<13;j++){
			string str=decade[i]+" "+unit[j];
			NumToStr[i*13+j]=str;
			StrToNum[str]=i*13+j;
		}
	}
}

int main(){
	int T;
	string str;
	init();
	cin>>T;
	getchar();
	while(T--){
		getline(cin,str);
		if(str[0]>='0'&&str[0]<='9'){
			int num=0;
			for(int i=0;i<str.length();i++){
				num=num*10+(str[i]-'0');
			}
			cout<<NumToStr[num]<<endl;
		}
		else{
			cout<<StrToNum[str]<<endl;
		}
	}
}
