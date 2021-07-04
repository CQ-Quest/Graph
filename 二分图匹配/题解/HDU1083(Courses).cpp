#include<bits/stdc++.h>
using namespace std;
int match[330][330],q,vis[330],a[330];
int dfs(int x){
	for(int i=1;i<=q;i++){
		if(match[x][i]&&!vis[i]){
			vis[i]=1;
			if(a[i]==0||dfs(a[i])){
				a[i]=x;
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--){
		int n,x,num;
		cin>>q>>n;
		memset(a,0,sizeof(a));
		memset(match,0,sizeof match);
		for(int i=1;i<=q;i++){
		 cin>>num;
		for(int j=1;j<=num;j++)
		 {
		  cin>>x;
		  match[x][i]=1;
		 }
	}
		int ans=0;
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof vis);
		if(dfs(i))  ans++;
	}
	if(ans==q)  cout<<"YES"<<endl;
	else  cout<<"NO"<<endl; 
	}
	return 0;
}
