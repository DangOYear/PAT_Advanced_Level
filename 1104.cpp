#include<iostream>
#include<iomanip>
using namespace std;

#define MAX_N 100005

double a[MAX_N];

int main(){
    int N;
    double sum=0;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>a[i];
        sum+=a[i]*(i+1)*(N-i);
    }

    cout<<fixed<<setprecision(2)<<sum<<endl;

}
