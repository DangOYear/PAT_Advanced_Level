#include<iostream>
#include<algorithm>
#include<vector>
#define MAX_N 100010
using namespace std;

int N;
long long a[MAX_N];
long long b[MAX_N];
vector<int> v;

int main(){
    cin>>N;
    int max=0;
    for(int i=0;i<N;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b,b+N);
    for(int i=0;i<N;i++){
        if(a[i]>max)    max=a[i];
        if(a[i]==b[i]&&b[i]==max){
            v.push_back(a[i]);
        }

    }
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i];
        if(i!=v.size()-1)   cout<<" ";
    }
    cout<<endl;
}
