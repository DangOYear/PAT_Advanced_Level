#include<iostream>
#include<string>
using namespace std;

#define MOD 1000000007
#define MAX_N   100005

int leftNum[MAX_N];//记录当前位置前P 的个数 

int main(){
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(i>0){
            leftNum[i]=leftNum[i-1];
        }

        if(s[i]=='P'){
            leftNum[i]++;
        }
    }

    int ans=0,rightNum=0;//A的个数 

    for(int i=s.length()-1;i>=0;i--){
        if(s[i]=='T'){
            rightNum++;
        }
        if(s[i]=='A'){ 
            ans=(ans+leftNum[i]*rightNum)%MOD;
        }
    }
    cout<<ans;
}
