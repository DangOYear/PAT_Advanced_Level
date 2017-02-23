#include<iostream>
#include<algorithm> 

using namespace std;

#define MAX_N 10010 

struct P{
    string name;
    int height;
}p[MAX_N];


bool cmp(struct P a,struct P b){
    if(a.height!=b.height)  return a.height<b.height;
    return a.name>b.name;
}


int main(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>p[i].name>>p[i].height;
    }
    sort(p,p+n,cmp);
    int raw=n/k;
    string result="";
    for(int i=0;i<k;i++){
        int begin=i*raw;
        int end=(i+1)*raw;
        if(end+raw>n)
            end=n;
        string line="";
        line=p[end-1].name;
        for(int j=end-2;j>=begin;j--){
            if(j%2!=end%2){
                line=line+" "+p[j].name;
            }
            else{
                line=p[j].name+" "+line;
            }
        }
        result=line+"\n"+result;
    }
    cout<<result;
}
