#include<iostream>
#include<string>

using namespace std;


string treat(string s,int &e,int n){
	int pos=0;
	while(s.length()>0&&s[0]=='0'){
		s.erase(s.begin());
	}
	if(s[0]=='.'){
		s.erase(s.begin());
		while(s.length()>0&&s[0]=='0'){
			s.erase(s.begin());
			e--;
		}
	}
	else{
		while(pos<s.length()&&s[pos]!='.'){
			pos++;
			e++;
		} 
		if(pos<s.length()){
			s.erase(s.begin()+pos);
		}
	}
	
	if(s.length()==0){
		e=0;
	}
	int num=0;
	pos=0;
	string result;
	while(num<n){
		if(pos<s.length())	result+=s[pos++];
		else	result+='0';
		num++;
	}
	return result;
	
}

int main(){
	int n;
	string s1,s2,s3,s4;
	cin>>n>>s1>>s2;
	int e1=0,e2=0;
	s3=treat(s1,e1,n);
	s4=treat(s2,e2,n);
	if(s3==s4&&e1==e2){
		cout<<"YES"<<" 0."<<s3<<"*10^"<<e1<<endl;
	}
	else{
		cout<<"NO"<<" 0."<<s3<<"*10^"<<e1<<" 0."<<s4<<"*10^"<<e2<<endl;
	}
}
