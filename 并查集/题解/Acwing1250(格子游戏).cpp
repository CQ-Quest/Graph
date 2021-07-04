#include<bits/stdc++.h>
using namespace std;
const int N=4e4+10;
int f[N],n,m;
int find(int x){
	if(f[x]!=x) f[x]=find(f[x]);
	return f[x];
}
void init(){
     for(int i=0;i<n*n;i++)
     f[i]=i;
}
int get(int x,int y){
	return x*n+y;
}
int main(){
	ios::sync_with_stdio(0);
	
	cin>>n>>m;
	int ans=0;
	init(); 
	for(int i=1;i<=m;i++){
		int x,y;
	    char c;
		cin>>x>>y>>c;
		
		x--,y--;
		int a=get(x,y),b;
		if(c=='D') b=get(x+1,y);
		else b=get(x,y+1); 
		int pa=find(a),pb=find(b);
		if(pa==pb){
			ans=i;
			break;
		}
		 f[pa]=pb;
	}
	if(!ans) cout<<"draw"<<endl;
	else cout<<ans<<endl;
	 return 0;
}
