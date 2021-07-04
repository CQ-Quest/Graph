#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
int n,m,val;
int f[maxn],w[maxn],v[maxn],dp[maxn]={0};
int find(int x){
	if(f[x]!=x){
	f[x]=find(f[x]);
	}
	return f[x];
}
void init(){
	for(int i=0;i<=maxn;i++)
	f[i]=i;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>val;
 init();
 for(int i=1;i<=n;i++) 
 cin>>v[i]>>w[i];
 while(m--){
 	int x,y;
 	cin>>x>>y;
 	int fa=find(x),fb=find(y); 
 	if(fa!=fb){
 		v[fb]+=v[fa];
 		w[fb]+=w[fa];
 		f[fa]=f[fb];
	 }
}
	 for(int i=1;i<=n;i++)
	 if(f[i]==i)
	 for(int j=val;j>=v[i];j--)
	 dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
	 
 cout<<dp[val]<<endl;
 return  0; 
} 
