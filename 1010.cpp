#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<string>
#include<math.h>

using namespace std;

typedef long long ll;

#define MAX_N 15

ll map[256];
ll INF=(1LL<<63)-1;

char N1[MAX_N],N2[MAX_N];
char temp[MAX_N];
int radix;
int tag;

ll toDecimal(char num[],int radix,ll top){
	ll ans=0;
	int l=strlen(num);
	for(int i=0;i<l;i++){
		ans=ans*radix+map[num[i]];
		//printf("ans=%d\n",ans);
		//printf("top=%lld\n",top);
		if(ans<0||ans>top)	return -1;
	}
	return ans;
}

void initmap(){
	for(char c='0';c<='9';c++){
		map[c]=c-'0';
	}
	for(char c='a';c<='z';c++){
		map[c]=c-'a'+10;
	}
}

ll findLargestDigit(char num[]){
	int ans=-1;
	int l=strlen(num);
	for(int i=0;i<l;i++){
		if(map[num[i]]>ans){
			ans=map[num[i]];
		}
	}
	return ans+1;
}

int cmp(char N2[],ll radix,ll top){
//	printf("%s %d\n",N2,radix);
	ll ans=toDecimal(N2,radix,top);
	//printf("cmp ans=%d\n",ans);
//	printf("%d\n",top);
	if(ans<0)
		return -1;
	if(top>ans)
		return 1;
	if(top==ans)
		return 0;
	return -1;
}

ll binarysearch(char N2[],ll low,ll high,ll top){
	ll mid=0;
	while(low<=high){
		mid=(low+high)/2;
		//printf("mid==%d\n",mid);
		int flag=cmp(N2,mid,top);
		if(flag==0)		return mid;
		if(flag==-1)	high=mid-1;
		if(flag==1)		low=mid+1;
	}
	return -1;
}


int main(){
	initmap();
	scanf("%s %s %d%d",N1,N2,&tag,&radix);
	if(tag==2){
		strcpy(temp,N1);
		strcpy(N1,N2);
		strcpy(N2,temp);
	}
	ll top=toDecimal(N1,radix,INF);
	ll low=findLargestDigit(N2);
	ll high=max(low,top)+1;
	//printf("%d",high);
	ll ans=binarysearch(N2,low,high,top);
	if(ans==-1)	printf("Impossible\n");
	else	printf("%lld\n",ans);
}

