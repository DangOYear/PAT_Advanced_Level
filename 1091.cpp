#include<stdio.h>
#include<queue>

#define MAX_X 1300
#define MAX_Y 130
#define MAX_Z 80

using namespace std;

int m,n,l,t;

struct Node{
	int x;
	int y;
	int z;
}node;

int matrix[MAX_X][MAX_Y][MAX_Z];
bool visited[MAX_X][MAX_Y][MAX_Z];

int X[6]={0,0,0,0,-1,1};
int Y[6]={0,0,-1,1,0,0};
int Z[6]={-1,1,0,0,0,0};

int bfs(int x,int y,int z){
	int coc=0;
	queue<Node> q;
	node.x=x;node.y=y;node.z=z;
	q.push(node);
	visited[x][y][z]=true;
	while(!q.empty()){
		Node front=q.front();
		coc++;
		q.pop();
		for(int i=0;i<6;i++){
			int newX=front.x+X[i];
			int newY=front.y+Y[i];
			int newZ=front.z+Z[i];
			if(newX<=m&&newX>=0&&newY<=n&&newY>=0&&newZ>=0&&newZ<=l&&!visited[newX][newY][newZ]&&matrix[newX][newY][newZ]){
				node.x=newX;node.y=newY;node.z=newZ;
				visited[newX][newY][newZ]=true;
				q.push(node);
			}
		}
	}
	if(coc>=t)	return coc;
	else	return 0;
}

int main(){
	scanf("%d%d%d%d",&m,&n,&l,&t);
	for(int z=0;z<l;z++){
		for(int x=0;x<m;x++){
			for(int y=0;y<n;y++){
				scanf("%d",&matrix[x][y][z]);
			}
		}
	}
	
	int count=0;
	for(int z=0;z<l;z++){
		for(int x=0;x<m;x++){
			for(int y=0;y<n;y++){
				if(matrix[x][y][z]==1&&!visited[x][y][z]){
					count+=bfs(x,y,z);
				}
			}
		}
	}
	printf("%d",count);
	
}
