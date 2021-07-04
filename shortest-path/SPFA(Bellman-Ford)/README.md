SPFA期望时间复杂度为O(KM)。M为边数，k是每个点平均入队次数  
可检验负环回路  

      #include<queue>
      #define maxn 1005
      #define INF 0x3f3f3f3f
      struct Node{
        int u,v,dis;       \\u,v,dis依次为点，边，起点
      };
      vector<Node>Adj[maxn];
      int n,d[maxn],num[maxn];
      bool check[maxn];
      bool SPFA(int s){
        int j,u,v,dis;
        memset(check,false,sizeof(check));
        memset(num,0,sizeof(num));
        fill(d,d+maxn,INF);
        queue<int>q;
        q.push(s);
        check[s]=true;
        num[s]++;
        d[s]=0;
        while(!q.empty()){
            u=q.front();
         q.pop();
         check[u]=false;
         for(j=0;j<Adj[u].size();j++){
          v=Adj[u][j].v;
          dis=Adj[u][j].dis;
          if(d[u]+dis<d[v]){
            d[v]=d[u]+dis;
            if(!check[v]){
              q.push(v);
              check[v]=true;
              num[v]++;
         if(num[v]>=n) return false;
             }
           }
         }	 
      }
          return true;
      }
——————————————————————————————————

    version2：
      #include <cstdio>
      #include <algorithm>
      #include <queue>
      #include<cstring>
      #define inf 0x3f3f3f3f
      using namespace std;
      typedef long long ll;
      const ll maxn = 20000;
      int n,m;
      int cost[maxn][maxn];
      ll dis[maxn]; 
      int vis[maxn];

      void spfa(){
          memset(dis,inf,sizeof(dis));
          memset(vis,0,sizeof(vis));
          queue<int> q;
          dis[1]=0;
          q.push(1);
          while(!q.empty())
          {
              int x=q.front();
              q.pop();
              vis[x]=0;
              if(dis[x]>dis[n]) continue;
              for(int i=1;i<=n;i++)
              {
                  if(i==x) continue;
                  if(dis[i]>dis[x]+cost[x][i])
                  {
                      dis[i]=dis[x]+cost[x][i];
                      if(!vis[i]) q.push(i);
                  }
              }
          }
      }
      int main(){
          while(~scanf("%d %d",&n,&m)&&(n+m))
          {
              int x,y,z;
              for(int i=1;i<=n;i++)
                  for(int j=1;j<=n;j++)
                      if(i==j) cost[i][j]=0;
                      else cost[i][j]=inf;
              for(int i=0;i<m;i++)
              {
                  scanf("%d %d %d",&x,&y,&z);
                  if(cost[x][y]>z)
                      cost[x][y]=cost[y][x]=z;
              }
              spfa();
              printf("%lld\n",dis[n]);
          }
          return 0;
      }
