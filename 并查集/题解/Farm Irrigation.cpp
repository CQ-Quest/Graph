#include<bits/stdc++.h>
using namespace std;
const int maxn=4e4;
char a[maxn][maxn];
int s[maxn];
void init(int n){
	for(int i=1;i<=n;i++)
	s[i]=i;
}
int find(int x){
    return s[x]==x?x:s[x]=find(s[x]);       
}
void merge(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y) return;
	else 
	s[x]=y;
}
int main(){
	int n,m;
	while(~scanf("%d %d",&n,&m)){
		if(m<0||n<0) return 0;
		init(n*m);
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		cin>>a[i][j];
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(j-1>=1)//保证不越界
            {
                if((a[i][j-1]=='B'||a[i][j-1]=='D'||a[i][j-1]=='F'||a[i][j-1]=='G'||a[i][j-1]=='I'||a[i][j-1]=='J'||a[i][j-1]=='K')
                   &&(a[i][j]=='C'||a[i][j]=='F'||a[i][j]=='G'||a[i][j]=='H'||a[i][j]=='I'||a[i][j]=='A'||a[i][j]=='K'))
                    merge((i-1)*m+j-1,(i-1)*m+j);
            }
            if(i-1>=1)
            {//当前田地是否能和上边的相邻的田地合并
                if((a[i-1][j]=='C'||a[i-1][j]=='D'||a[i-1][j]=='E'||a[i-1][j]=='H'||a[i-1][j]=='I'||a[i-1][j]=='J'||a[i-1][j]=='K')&&
                   (a[i][j]=='A'||a[i][j]=='B'||a[i][j]=='E'||a[i][j]=='G'||a[i][j]=='H'||a[i][j]=='J'||a[i][j]=='K'))
                    merge((i-1-1)*m+j,(i-1)*m+j);
            }
        }
        int num=0;
        for(int i=1;i<=n*m;i++)
            if(s[i]==i) num++;
          printf("%d\n",num);
    }
    return 0;
}
