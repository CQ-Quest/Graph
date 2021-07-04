#路径压缩查询

    int find(int x){
       if(f[x]!=x) f[x]=find(f[x]);
       return f[x];
       }
    
 带权并查集查询
        
     int find(int x){
       if(f[x]!=x) {
       int root=f[x];
       f[x]=find(f[x]);
       w[x]+=w[root];
       }
       return f[x];
    }
    
 非递归查询
   
    int find(int x){
       int j,k,r;
       r=x;
       while(f[r]!=r)
       r=f[r];
       k=x;
       while(k!=r)
      {
        j=f[k];
        f[k]=r;
        k=j;
       }
       return r
       }
       
#合并
    
    void merge(int x,int y){
       x=find(x);
       y=find(y);
       if(x!=y)
       s[x]=y;
       return 
    }
