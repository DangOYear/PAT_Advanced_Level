#include<iostream>  
#include<algorithm>  
#include<iomanip>  
using namespace std;  
  
struct mooncake{  
    double num;  
    double prize;  
    double singleprize;   
};  
  
bool cmp(struct mooncake a,struct mooncake b)  
{  
    return a.singleprize>b.singleprize;  
}  
  
int main()  
{  
    int N,D,i;  
    struct mooncake mc[10004];  
    double income=0;  
    cin>>N>>D;  
    for(int i=0;i<N;i++)  
    {  
        cin>>mc[i].num;  
    }  
    for(int i=0;i<N;i++)  
    {  
        cin>>mc[i].prize;  
    }  
    for(int i=0;i<N;i++)  
    {  
        mc[i].singleprize=mc[i].prize/mc[i].num;  
    }  
    sort(mc,mc+N,cmp);  
    i=0;  
    while(D>0&&i<N)  
    {  
        if(D-mc[i].num>=0)  
        {  
            income+=mc[i].prize;  
            D-=mc[i].num;  
        }  
        else  
        {  
            income+=D*mc[i].singleprize;  
            D=0;  
        }     
        i++;  
    }  
    cout<<fixed<<setprecision(2)<<income;  
}  
