#include<iostream>
#include<cstdio>
using namespace std;
int arr[5][5],dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
bool vis[5][5];
int record[30][2],ans[30][2],cnt=1<<30;
void print(int num)
{
    cout << "(0, 0)" << endl;
    for(int i=0;i<num;i++)
        cout << "(" << ans[i][0] << ", " << ans[i][1] << ")" << endl;
}
void dfs(int x,int y,int num)
{
	 int i,dx,dy;
    if(x==4 && y==4 && num<cnt)
    {
        cnt=num;
        for(i=0;i<cnt;i++)
            ans[i][0]=record[i][0],ans[i][1]=record[i][1];
        return;
    }
    for(i=0;i<4;i++)
    {
         dx=x+dir[i][0];
         dy=y+dir[i][1];
        if(dx>=0&&dy>=0&&dx<5&&dy<5&&!vis[dx][dy]&&arr[dx][dy]==0)
        {
            vis[dx][dy]=true;
            record[num][0]=dx;
			record[num][1]=dy;
            dfs(dx,dy,num+1);
            vis[dx][dy]=false;
        }
    }
}
int main()
{
	int i,j;
    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
           scanf("%d",&arr[i][j]);
    dfs(0,0,0);
    print(cnt);
    return 0;
}

