#include<iostream>
#include<string>
#include<map>

using namespace std;

bool check(char c){
	if(c<='z'&&c>='a')	return true;
	if(c<='Z'&&c>='A')	return true;
	if(c<='9'&&c>='0')	return true;
	return false;
}

int main(){
	map<string,int> word_count;
	string str;
	getline(cin,str);
	int i=0;
	while(i<str.length()){
		string word="";
		while(i<str.length()&&check(str[i])){
			if(str[i]<='Z'&&str[i]>='A')
				str[i]+=32;
			word+=str[i];
			i++;
		}
		if(word!=""){
			if(word_count.find(word)!=word_count.end())	word_count[word]++;
			else	word_count[word]=1;
		}
		while(i<str.length()&&!check(str[i])){
			i++;
		}
	}
	
	string res;
	int max=0;
	
	for(map<string,int>::iterator it=word_count.begin();it!=word_count.end();it++){
		if(it->second>max){
			res=it->first;
			max=it->second;
		}
	}
	cout<<res<<" "<<max<<endl;
}
