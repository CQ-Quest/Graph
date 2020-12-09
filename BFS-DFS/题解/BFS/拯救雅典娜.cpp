#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=200;
int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
char a[maxn][maxn];
int vis[maxn][maxn],ans;
int sx,sy,n,m,t;
void dfs(int x,int y,int T){
	int dx,dy;
	if(T==t) return;
	for(int i=0;i<4;i++){
		dx=x+dir[i][0];
		dy=y+dir[i][1];
		if(!vis[dx][dy]&&(a[dx][dy]=='.'||a[dx][dy]=='E')){
			vis[dx][dy]=1;
			if(a[dx][dy]=='E'){
				ans=1;
				return ;
			}
			else
			dfs(dx,dy,T+1);
			if(ans==1) return;
			vis[dx][dy]=0;
		}
	}
}
int main(){
	while(~scanf("%d %d %d",&n,&m,&t)&&n&&m&&t){
		memset(vis,0,sizeof(vis));
		memset(a,'\0',sizeof(a));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
				if(a[i][j]=='S'){
					sx=i,sy=j;
				}
			}
		}
		vis[sx][sy]=1;
		ans=0;
		dfs(sx,sy,1);
		printf("%s\n",ans?"Oh Yes!!!":"Tragedy!!!"); 
	}
   return 0;
}
