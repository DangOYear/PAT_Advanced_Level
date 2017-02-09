#include<iostream>
#include<string>
using namespace std;

void day(int i){
    string s[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
    cout<<s[i-1]<<" ";
}

void hour(char c){
    if(c<='9'&&c>='0')  cout<<"0"<<c-'0';
    if(c<='N'&&c>='A')  cout<<c-'A'+10;
    cout<<":";
}

void min(int i){
    if(i<=9)    cout<<"0";
    cout<<i;
}

int main(){
    string s[4];
    bool first=true;

    cin>>s[0];
    cin>>s[1];
    cin>>s[2];
    cin>>s[3];

    for(int i=0;i<s[0].length()&&i<s[1].length();i++){

        if(first&&s[0][i]==s[1][i]&&(s[0][i]<='G'&&s[0][i]>='A'))
        {
            day(s[0][i]-'A'+1);
            first=false;
            continue;
        }   
        if(first!=true&&s[0][i]==s[1][i]&&((s[0][i]<='N'&&s[0][i]>='A')||(s[0][i]<='9'&&s[0][i]>='0')))
        {
            hour(s[0][i]);
            break;
        }
    }
    for(int i=0;i<s[2].length()&&i<s[3].length();i++){
        if(s[2][i]==s[3][i]&&(s[2][i]<='Z'&&s[2][i]>='A'||s[2][i]<='z'&&s[2][i]>='a'))
            min(i);
    }

}
