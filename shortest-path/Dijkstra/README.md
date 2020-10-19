Dijkstra:典型单源最短路径，采用贪心算法，具体为以起始点为中心向外层层拓展，  
直至拓展到终点为止。源点处dis的值为0，且每次找最近的点松弛。  
直白点说，就是每次用当前dis最小的节点去更新别的节点，直至找出最短路径。    
  
      int Dijkstra(int n,int m){
        memset(dis,0,sizeof(dis));
        memset(check,0,sizeof(check));
        int i,j;
        for(i=1;i<=n;i++)
        dis[i]=map[1][i];
        check[1]=1;
        dis[1]=0;
        int minx=0,pos;
        for(i=1;i<=n;i++){
        minx=INF;
        for(j=1;j<=n;i++)
        if(!check[j]&&minx>dis[j]){
          minx=dis[j];
          pos=j;
        }
        }
        check[pos]=1;
        for(j=1;j<=n;j++){
          if(!check[j]&&dis[j]>dis[pos]+map[pos][j])
          dis[j]=dis[pos]+map[pos][j];
        }
      }
        return dis[n];
      } 

[注]：Dijkstra算法不能处理负权边。若存在负权边，可能会通过并不是距源点最近的一个次优点,  
再通过这个负权边L(L<0)，使得路径之和更小，即dmin'+L<dmin,dmin'+L成为最短路径，却并不是dmin。


Dijkstra + 堆优化（优先队列）：  

        #include<bits/stdc++.h>
        using namespace std;
        typedef long long ll;
        typedef pair<int, int> pii;
        const int N = 1e5 + 10;
        const ll inf = (ll)1e16;

        int n, m;
        bool vis[N];
        ll dis[N];
        vector <pii> g[N];

        struct Node{
          int id; ll d;
          Node() {}
          Node(int id, ll d):id(id),d(d){}
          bool operator < (const Node &A) const {
            return d > A.d;
          }
        };

        void dijkstra(int st){
          for(int i=1; i<=n; i++){
            vis[i] = 0;
            dis[i] = inf;
          }

          dis[st] = 0;
          priority_queue <Node> Q;
          Q.push(Node(st, 0));
          Node nd;

          while(!Q.empty()){
            nd = Q.top(); Q.pop();
            if(vis[nd.id]) continue;
            vis[nd.id] = true;
            for(int i=0; i<g[nd.id].size(); i++){
              int j = g[nd.id][i].first;
              int k = g[nd.id][i].second;
              if(nd.d + k < dis[j] && !vis[j]){
                dis[j] = nd.d + k;
                Q.push(Node(j, dis[j]));
              }
            }
          }
        }

        int main(){
          int x, y, z, st, ed, cas = 0;
          scanf("%d", &cas);
          while(cas--){
            scanf("%d%d%d", &n, &m, &st);
            for(int i=1; i<=n; i++) g[i].clear();
            while(m--){
              scanf("%d%d%d", &x, &y, &z);
              g[x].push_back(make_pair(y, z));
              //g[y].push_back(make_pair(x, z));
            }
            dijkstra(st);
            for(int i=1; i<=n; i++)
              printf("%d%s", dis[i], " \n"[i==n]);
          }
        }

