#include<stdio.h>

int main(){
	int n;
	int ans=0;
	int left;//��ǰλǰ���λ��
	int right;//��ǰλ�����λ�� 
	int a=1;
	int pos;//��ǰλ 
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
