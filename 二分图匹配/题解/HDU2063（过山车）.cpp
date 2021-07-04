#include<bits/stdc++.h>
using namespace std;
const int maxn=502;
vector<int>v[maxn];
int vis[maxn]={0},match[maxn]={0};
int dfs(int x){
	for(int i=0;i<v[x].size();i++){  
		int o=v[x][i];
		if(!vis[o]){
			vis[o]=1;
			if(match[o]==-1||dfs(match[o])){
				match[o]=x;
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	int k,n,m;
	while(cin>>k&&k){
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		if(v[i].size()) 
		  v[i].clear();
		while(k--){
			int z,x;
			cin>>z>>x;
			v[z].push_back(x);
		}
		memset(match,-1,sizeof match);
		int ans=0;
		for(int i=1;i<=n;i++){
			memset(vis,0,sizeof vis);
			if(dfs(i)) ans++;
		}
		int k=min(n,m);
		ans=min(ans,k);
		cout<<ans<<endl; 
	}
	return 0;
}
//#include <iostream>
//#include <vector>
//#include <cstring>
//#include <cstdio>
//using namespace std;
//int vis[505],link[505];
//vector<int>mp[505];
//int n,m;
//int dfs(int x)
//{
//    for(int i=0;i<mp[x].size();i++)
//    { int v=mp[x][i];
//        if(!vis[v])
//        {
//            vis[v]=1;
//            if(link[v]==-1||dfs(link[v]))
//            {   link[v]=x;
//                return 1;}
//        }
//    }
//    return 0;
//}
//int main()
//{  int k,a,b;
//    while(cin>>k)
//{   if(k==0)
//   break;
//   cin>>n>>m;
//    for(int i=1;i<=n;i++)
//    if(mp[i].size())
//    mp[i].clear();
//    while(k--)
//    {
//        scanf("%d%d",&a,&b);
//        mp[a].push_back(b);
//    }
//    memset(link,-1,sizeof(link));
//    int res=0;
//    for(int i=1;i<=n;i++)
//    {   memset(vis,0,sizeof(vis));
//        if(dfs(i))
//        res++;
//    }
//    cout<<res<<endl;
//
//}
//    }
