#include<iostream>
#include<vector>
using namespace std;

vector<string> v;

int main(){
	int N;
	string s;
	int minLen=300;
	int count=0;
	cin>>N;
	//cin.sync();//Çå¿Õ»º³åÇø 
	getchar();
	for(int i=0;i<N;i++){
		
		
		getline(cin,s);
		v.push_back(s);
		int len=s.length();
		if(len<minLen)	minLen=len;
		for(int j=0;j<len/2;j++){
			char temp=v[i][j];
			v[i][j]=v[i][len-1-j];
			v[i][len-1-j]=temp;
		}
		
	}
	
	for(int i=0;i<minLen;i++){
		char c=v[0][i];
		bool same=true;
		for(int j=1;j<v.size();j++){
			if(c!=v[j][i]){
				same=false;
				break;
			}
		}
		if(same)	count++;
		else	break;
	}
	if(count){
		for(int i=count-1;i>=0;i--){
			cout<<v[0][i];
		}
		cout<<endl;
	}
	else	cout<<"nai"<<endl;
	
	
}
