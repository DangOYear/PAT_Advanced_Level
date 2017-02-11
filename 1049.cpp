#include<stdio.h>

int main(){
	int n;
	int ans=0;
	int left;//当前位前面的位数
	int right;//当前位后面的位数 
	int a=1;
	int pos;//当前位 
	scanf("%d",&n);
	while(n/a!=0){
		left=n/(a*10);
		pos=n/a%10;
		right=n%a;
		if(pos==0)	ans+=left*a;
		else if(pos==1)	ans+=left*a+right+1;
		else ans+=(left+1)*a;
		a*=10;
	}
	printf("%d\n",ans);
}
