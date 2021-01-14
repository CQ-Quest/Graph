#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
struct node{
    int x,y,step;
    friend bool operator<(node a,node b){
        return b.step<a.step;
    }
};
int n,m,vis[205][205];
char map[205][205];
int x1,y1;
int to[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
 
int bfs(){
    priority_queue<node>q;
    node a,next;
    a.x = x1;
    a.y = y1;
    a.step = 0;
    q.push(a);
    vis[x1][y1] = 0;
    while(!q.empty())
    {
        a = q.top();
        q.pop();
        if(map[a.x][a.y]=='a')
            return a.step;
        for(int i=0;i<4;i++)
        {
            next = a;
            next.x+=to[i][0];
            next.y+=to[i][1];
            if(next.x>=0&&next.x<n&&next.y>=0&&next.y<m&&vis[next.x][next.y]&&map[next.x][next.y]!='#'){
            next.step++;
            if(map[next.x][next.y] == 'x')  next.step++;
            if(vis[next.x][next.y]>=next.step){
                vis[next.x][next.y] = next.step;
                q.push(next);
            }
        }
    }
}
    return 0;
}
 
int main()
{
    int i,j;
    while(~scanf("%d%d",&n,&m))
    {
        for(i = 0; i<n; i++)
        {
            scanf("%s",map[i]);
            for(j = 0; map[i][j]; j++)
            {
                if(map[i][j] == 'r')
                {
                    x1 = i;
                    y1 = j;
                }
            }
        }
        memset(vis,1,sizeof(vis));
        int ans = 0;
        ans = bfs();
        if(ans)
            printf("%d\n",ans);
        else
            printf("Poor ANGEL has to stay in the prison all his life.\n");
    }
 
    return 0;
}
