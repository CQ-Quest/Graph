#include<iostream>
#include<cstring>
using namespace std;
const int maxn=300;
int vis[maxn][maxn];
char a[maxn][maxn];
int dir1[4]={1,0,-1,0};
int dir2[4]={1,0,-1,0};
int n,m;
void DFS(int x,int y){
	vis[x][y]=1;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++)
		{
			int dx=x+dir1[i];
			int dy=y+dir2[j];
			if(dx>=0&&dx<m&&dy>=0&&dy<n&&a[dx][dy]=='W'&&!vis[dx][dy]){
				DFS(dx,dy);
			}
		}
	}
}
int main(){
	int i,j,ans=0;
	while(cin>>m>>n&&n&&m){
		ans=0;
		memset(vis,0,sizeof(vis));
		memset(a,'.',sizeof(a));
		for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
		cin>>a[i][j];
		for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]=='W'&&!vis[i][j]){
				ans++;
				DFS(i,j);
			}
		}
	}
		cout<<ans<<endl; 
	}
}
