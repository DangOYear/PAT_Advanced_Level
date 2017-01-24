#include<stdio.h>
#include<math.h>
#include<algorithm>

using namespace std;

typedef long long ll;

ll gcd(ll a,ll b){
	if(a%b==0)
		return b;
	else
		return gcd(b,a%b);
}

struct Fraction{
	ll up;
	ll down;
};

Fraction reduction(Fraction result){
	if(result.down<0){
		result.up=-result.up;
		result.down=-result.down;
	}
	
	if(result.up==0){
		result.down=1;
	}else{
		int d=gcd(abs(result.down),abs(result.up));
		//printf("%d\n",d);
		result.down/=d;
		result.up/=d;
	}
	
	//printf("%lld ",result.up);
	//printf("%lld\n",result.down);
	return result;
}

Fraction add(Fraction a,Fraction b){
	Fraction result;
	result.up=a.down*b.up+a.up*b.down;
	result.down=a.down*b.down;
	//printf("%lld ",result.up);
	//printf("%lld\n",result.down);
	return reduction(result);
}

void showResult(Fraction r){
	r=reduction(r);
	if(r.down==1)	printf("%lld\n",r.up);
	else if(abs(r.up)>r.down)	printf("%lld %lld/%lld\n",r.up/r.down,abs(r.up)%r.down,r.down);
	else	printf("%lld/%lld\n",r.up,r.down);
}

int main(){
	int n;
	scanf("%d",&n);
	Fraction sum,temp;
	sum.down=1;sum.up=0;
	
	for(int i=0;i<n;i++){
		scanf("%lld/%lld",&temp.up,&temp.down);
		sum=add(sum,temp);
		//showResult(sum);
	}
	
	showResult(sum);
	return 0;
}
