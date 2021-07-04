
#二分图

    二分图(Graph)      
    biGraph()若返回0，则不能构成二分图，返回1则能。  
    color数组里装的是每个节点的颜色，1是黑，-1是白，0代表还没有赋值颜色。      

     #define pb push_back
     #define _for(i,a,b) for(int i = (a);i < (b);i ++)
     const int maxn = 50003; 

     vector<int> G[maxn];
     int V;
     int color[maxn];
     bool dfs(int v,int c)
     {
         //给当前节点颜色，1或-1 
         color[v] = c;
         //检查每个邻接节点，若不符合要求就return false 
         for(int i = 0;i < G[v].size();i ++)
         {
             //如果邻接点和当前节点颜色重复 
             if(color[G[v][i]] == c) return false;
             //如果邻接点没有颜色但是继续向下的时候出现问题 
             if(color[G[v][i]] == 0 && !dfs(G[v][i],-c)) return false;
         }
         return true;
     }
     int biGraph()
     {
         memset(color,0,sizeof(color));
        //遍历每个节点 
         for(int i = 0;i < V;i ++)
             if(color[i]==0)
            if(!dfs(i,1))         return 0;
       return 1;
        }
