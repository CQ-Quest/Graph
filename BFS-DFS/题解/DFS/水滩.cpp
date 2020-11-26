#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
#define N 1001
char map[N][N];
int n,m,dir[4][2]={{-1,0},{0,-1},{0,1},{1,0}};
bool vis[N][N];
struct Node{
    int x,y;
    Node(){}
    Node(int x,int y):x(x),y(y){}
};
int bfs(int x,int y){
	int dx,dy,cnt,left;
queue<Node> q;
Node node;
q.push(Node(x,y));
node.x=0;
node.y=0;
vis[x][y] = true; 
  left = 0;
while(!q.empty()){
 node = q.front();
q.pop();
for(int i = 0;i < 4;i++){
   dx = node.x + dir[i][0];
   dy = node.y + dir[i][1];
if(map[dx][dy] == 'W' && dx >= 0 && dx < m && dy >= 0 && dy < n){		
  if(!vis[dx][dy]){
vis[dx][dy] = true;
q.push(Node(dx,dy));	
}
} 
}
left++;	
}
return left;
}
int main(){
int i,j,ans = 0;
    while(cin>>n>>m){
for(i = 0;i < m;i++)
for(j = 0;j < n;j++)
cin >> map[i][j];
for(i = 0;i < m;i++)
for(j = 0;j < n;j++){
if(map[i][j] == 'W' && !vis[i][j])
	if(!bfs(i,j)){ 
	ans++;
	} 
}
cout << ans << endl;
}
return 0;
}
