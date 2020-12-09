#include<cstdio>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=100;
int vis[maxn][maxn],fire[maxn][maxn];
char a[maxn][maxn];
int n,m,ans;
int dir1[4]={-1,1,0,0};
int dir2[4]={0,0,1,-1};
struct node{
int x,y,step;};
int BFS(int x,int y){
	queue<node>q;
	node Node,next;
	Node.x=x;
	Node.y=y;
	Node.step=0;
	q.push(Node);
	while(!q.empty()){
		Node=q.front();
		q.pop();
		if(a[Node.x][Node.y]=='E')
		return Node.step;
		if(fire[Node.x][Node.y]==Node.step)
		continue;
		for(int i=0;i<4;i++){
			next.x=Node.x+dir1[i];
		    next.y=Node.y+dir2[i];
		    next.step=Node.step+1;
		   if(next.step<=fire[next.x][next.y]&&next.x>=0&&next.x<n&&next.y>=0&&next.y<m&&!vis[next.x][next.y]&&a[next.x][next.y]!='#'){
		   	q.push(next);
		   	vis[next.x][next.y]=1;
		   } 
		    
		}	
	} 
   return 0;
}
int main(){
	int t;
	int s1,s,e1,e;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		memset(vis,0,sizeof(vis));
		memset(a,'#',sizeof(a));
		memset(fire,0,sizeof(fire));
		for(int i=0;i<n;i++){
			char c=getchar();
			for(int j=0;j<m;j++)
			scanf("%c",&a[i][j]); 
		}
		for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			if(a[i][j]=='S'){
				s=i;
				e=j;
			}
			if(a[i][j]=='*')
			s1=i,e1=j;
		}
		for(int i=0;i<n;i++)
		for(int j=0;j<m;j++) 
		fire[i][j]=max(abs(i-s1),abs(j-e1));
		ans=BFS(s,e);
		if(ans)  printf("%d\n",ans);
		else printf("T_T\n");
	}
	return 0;
}
