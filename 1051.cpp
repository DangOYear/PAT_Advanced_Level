#include<stdio.h>
#include<stack>

#define MAX_N 1100


using namespace std;

int arr[MAX_N];
stack<int> st;


int main(){
	int m,n,k;
	scanf("%d%d%d",&m,&n,&k);
	while(k--){
		while(!st.empty()){
			st.pop();
		}
		for(int j=1;j<=n;j++){
			scanf("%d",&arr[j]);
		}
		int current=1;
		bool flag=true;
		for(int i=1;i<=n;i++){
			st.push(i);
			if(st.size()>m){
				flag=false;
				break;
			}
			while(!st.empty()&&st.top()==arr[current]){
				st.pop();
				current++;
			}
		}
		if(st.empty()&&flag){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
		
	}
}
