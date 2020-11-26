#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int n,m,t;
bool vis[10][10];
char a[10][10];
int sx,sy,ex,ey;
int flag;
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
void dfs(int x,int y,int cnt)
{
    if(cnt==t&&x==ex&&y==ey){
        flag=1;
        return ;
    }
    int ret=abs(ex-sx)+abs(ey-sy)-t;
        if(ret>0||ret&1)  return;
        
        if(flag) return ;
    for(int i=0;i<4;i++){
        int dx=x+dir[i][0];
        int dy=y+dir[i][1];
        if(dx<0||dx>=n||dy<0||dy>=m||a[dx][dy]=='#'||vis[dx][dy]) continue;
        vis[dx][dy]=1;
        dfs(dx,dy,cnt+1);
        vis[dx][dy]=0;
    }
}
int main()
{
    while(cin>>n>>m>>t&&n&&m){
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                cin>>a[i][j];
                if(a[i][j]=='S'){
                    sx=i;
					sy=j;
                }
                if(a[i][j]=='E'){
                    ex=i;
					ey=j;
                }
            }
        }
        flag=0;
        vis[sx][sy]=1;
        dfs(sx,sy,0);
        if(flag) cout<<"Oh Yes!!!"<<endl;
        else cout<<"Tragedy!!!"<<endl;
    }
    return 0;
}
