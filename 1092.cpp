#include<iostream>
#include<map>
#include<set>
using namespace std;



int main(){
    map<char,int> mp1,mp2;
    set <char> s;
    set<char>::iterator it;
    string s1,s2;
    int less=0;
    bool flag=true;
    cin>>s1>>s2;
    for(int i=0;i<s1.length();i++){
        mp1[s1[i]]++;
    }
    for(int i=0;i<s2.length();i++){
        mp2[s2[i]]++;
        s.insert(s2[i]);
    }


    for(it=s.begin();it!=s.end();it++){
        if(mp2[*it]>mp1[*it]){
            less+=mp2[*it]-mp1[*it];
            flag=false;
        }
    }

    if(flag)    cout<<"Yes "<<s1.length()-s2.length()<<endl;
    else    cout<<"No "<<less<<endl;

}
