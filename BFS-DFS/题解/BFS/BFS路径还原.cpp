#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int a[6][6],dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
bool vis[6][6];
struct Node{
	int x;
	int y;
}old[5][5];
void BFS(){
	Node node;
	int i,dx,dy;
	queue<Node>q;
	node.x=0;
	node.y=0;
	vis[node.x][node.y]=true;
	q.push(node);
	while(!q.empty()){
		node=q.front();
		q.pop();
		if(node.x==4&&node.y==4) break;
		for(i=0;i<4;i++){
			dx=node.x+dir[i][0];
			dy=node.y+dir[i][1];
			if(dx>=0&&dy>=0&&dx<=4&&dy<=4&&a[dx][dy]==0&&!vis[dx][dy]){
				vis[dx][dy]=true;
				old[dx][dy].x=node.x;
				old[dx][dy].y=node.y;
				node.x=dx;
				node.y=dy;
				q.push(node);
			}
		}
	}
	}
void print(int x,int y){
	if(x==0&&y==0){
		cout<<"(0, 0)"<<endl;
   return;
	}
	print(old[x][y].x,old[x][y].y);
	cout<<"("<<x<<", "<<y<<")"<<endl;
}
int main(){
	int i,j;
	for(i=0;i<5;i++)
	for(j=0;j<5;j++)
	cin>>a[i][j];
	BFS();
	print(4,4);
	return 0;
	} 
