#include<stdio.h>
#include<algorithm>
#include<vector>

#define MAX_N 110

int ins[MAX_N],heap[MAX_N],aim[MAX_N];
int n;

void show(int a[]){
	for(int i=1;i<=n;i++){
		printf("%d",a[i]);
		if(i!=n)
			printf(" ");
	}
}

bool isSame(int a[],int b[]){
	bool flag=true;
	for(int i=1;i<=n;i++){
		if(a[i]!=b[i]){
			flag=false;
			break;
		}
	}
	return flag;
}

bool Insert(){
	bool flag=false;
	for(int i=2;i<=n;i++){
		if(i!=2&&isSame(ins,aim)){
			flag=true;
		}
		int key=ins[i];
		int j=i;
		while(j>1&&ins[j-1]>key){
			ins[j]=ins[j-1];
			j-=1;
		}
		ins[j]=key;
		if(flag){
			return true;
		}
	}
	return false;
}

void HeapAdjust(int s,int m){
	int rc=heap[s];
	for(int j=2*s;j<=m;j*=2){
		if(j<m&&heap[j]<heap[j+1])	j++;
		if(rc>heap[j])	break;
		heap[s]=heap[j]; s=j;
	}
	heap[s]=rc;
}

void HeapSort(){
	bool flag=false;
	for(int i=n/2;i>0;i--){
		HeapAdjust(i,n); 
	}
	for(int i=n;i>1;--i){
		if(i!=n&&isSame(heap,aim)){
			flag=true;
		}
		int temp=heap[1];
		heap[1]=heap[i];
		heap[i]=temp;
		HeapAdjust(1,i-1);
		if(flag){
			return;
		}
	} 
}



int main(){
	scanf("%d",&n);
	//堆排一般下标为1开始 
	for(int i=1;i<=n;i++){
		scanf("%d",&ins[i]);
		heap[i]=ins[i];
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&aim[i]);
	}
	if(Insert()){
		printf("Insertion Sort\n");
		show(ins);
	}else{
		printf("Heap Sort\n");
		HeapSort();
		show(heap);
	}
	
}
