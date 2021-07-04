#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
struct node{
    int x,y,t;
} s[maxn];

int n,m,f[maxn];
bool cmp(node a,node b){
    return a.t>b.t;
}
void init(){
    for(int i=1;i<=n;i++)
        f[i]=i;        
}
int find(int x){
    return f[x]==x?x:f[x]=find(f[x]);
}
int merge(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y) return 0;
   else if(x!=y) 
        f[x]=y; 
	return 1; 
}
int main(){
    while (~scanf("%d%d",&n,&m)){
        for (int i=1; i<=m; i++)
            scanf("%d%d%d",&s[i].x,&s[i].y,&s[i].t);
        sort(s+1,s+m+1,cmp);
          init();
        int pre=-1,ans=0,way;
        for (int i=1; i<=m; i++){
            way=merge(s[i].x,s[i].y);
            if (way&&s[i].t!=pre){
                ans++;
                pre=s[i].t;
      }
  }
       printf("%d\n",ans);
        }
    return 0;
}
