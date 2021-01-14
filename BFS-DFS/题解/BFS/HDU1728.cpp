//#include<cstdio>
//#include<cstring>
//#include<queue>
//using namespace std;
// struct P
//{
//    int x,y;
//    int counts;
//    friend bool operator<(P a,P b){
//    	return b.counts<a.counts;
//	}
//};
//char a[105][105];
//int vis[105][105];
//const int dx[]= {1,0,-1,0};
//const int dy[]= {0,1,0,-1};
//int n,m,x1,y1,x2,y2,k;
//int judge(int x ,int y)
//{
//    if(x>=0&&x<n&&y>=0&&y<m&&a[x][y]!='*')
//        return 1;
//    return 0;
//}
//int bfs()
//{
//    int i,nx,ny;
//    priority_queue<P>que;
//    P p,tp;
//    p.x = x1;
//    p.y = y1;
//    p.counts =-1;
//    que.push(p);
//    while(!que.empty())
//    {
//        p = que.top();
//        que.pop();
//        if(p.counts>k)                  //如果出现转弯次数大于K，则代表无法在次数限制内到达终点
//            return 0;
//        tp = p;
//        tp.counts = p.counts+1;         //从队列中取出后，一定会发生转向
//        for(i=0; i<4; i++)
//        {
//            nx = p.x + dx[i];
//            ny = p.y + dy[i];
//            while(judge(nx,ny))       //不发生转向，沿同一方向一直访问至尽头
//            {
//                if(vis[nx][ny]==0)     //当该地址未被访问才进入队列
//                {
//                    tp.x = nx;
//                    tp.y = ny;
//                    que.push(tp);
//                    vis[nx][ny]=1;
//                }
//                if(nx==x2&&ny==y2)
//                {
//                    if(tp.counts<=k)
//                        return 1;
//                    else
//                        return 0;
//                }
//                nx = nx + dx[i];
//                ny = ny + dy[i];
//            }
//        }
//    }
//    return 0;
//}
//int main(){
//    int t,i,j;
//    scanf("%d",&t);
//    while(t--)
//    {
//    	memset(vis,0,sizeof(vis));
//        scanf("%d%d",&n,&m);
//        for(i=0; i<n; i++)
//        	scanf("%s",a[i]);
//        scanf("%d%d%d%d%d",&k,&x1,&y1,&x2,&y2);
//        vis[x1][y1]=1;
//        int ans=bfs();
//        if(ans)  puts("yes");
//        else puts("no");
//    }
//    return 0;
//}
#include<cstdio>
#include<cstring>
#include<queue>
#include<iostream>
using namespace std;
const int N = 105;
 
char G[N][N];
bool vis[N][N];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m, limit, sx, sy, ex, ey;
 
struct node
{
    int x, y, step;
};
 
bool check(int x, int y)
{
    if(x>=1 && x<=m && y>=1 && y<=n && G[x][y]!='*') return true;
    else return false;
}
 
void bfs(int x, int y)
{
    if(x==ex && y==ey){
        puts("yes");
        return;
    }
    memset(vis, false, sizeof(vis));
    queue<node>que;
    node s;
    s.x = x;
    s.y = y;
    s.step = -1;
    vis[x][y] = true;
    que.push(s);
    while(!que.empty())
    {
        node tmp = que.front();
        que.pop();
        for(int i = 0; i < 4; i++)
        {
            node tmp2;
            tmp2 = tmp;
            tmp2.x += dir[i][0];
            tmp2.y += dir[i][1];
            while(check(tmp2.x, tmp2.y))
            {
                if(!vis[tmp2.x][tmp2.y])
                {
                    vis[tmp2.x][tmp2.y] = true;
                    tmp2.step = tmp.step+1;
                    if(tmp2.x == ex && tmp2.y == ey && tmp2.step<=limit)
                    {
                        printf("yes\n");
                        return;
                    }
                    que.push(tmp2);
                }
                tmp2.x += dir[i][0];
                tmp2.y += dir[i][1];
            }
        }
    }
    printf("no\n");
    return;
}
 
int main(){
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &m, &n);
        for(int i = 1; i <= m; i++)
            for(int j=1;j<=n;j++)
            cin>>G[i][j];
        scanf("%d%d%d%d%d", &limit, &sy, &sx, &ey, &ex);
        bfs(sx, sy);
    }
    return 0;
}
