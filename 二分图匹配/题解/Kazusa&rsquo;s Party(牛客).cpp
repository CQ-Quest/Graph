//#include<bits/stdc++.h>
//using namespace std;
//const int maxn=1e5+10;
//int a[maxn],b[maxn];
//bool cmp(int z,int x){
//	return z>x;
//}
//int main(){
//	ios::sync_with_stdio(0);
//	int n;
//	cin>>n;
//	for(int i=0;i<n;i++)
//	cin>>a[i];
//	for(int i=0;i<n;i++)
//	cin>>b[i];
//	sort(a,a+n,cmp);
//	int ans=0;
//	for(int i=0; i<n; i++){
//            if(b[i]==-1) continue;
//            if(__gcd(a[i],b[i])>1){
//                ans++;
//                b[i] = -1;
//                break;
//            }
//        }
//    cout<<ans<<endl;
//    return 0;
//} 
#include<bits/stdc++.h>
using namespace std;
int match[10][10],vis[10];
int a[10],b[10],n;
int dfs(int x){
	for(int i=1;i<=n;i++){
		if(match[x][i]&&!vis[i]){
			vis[i]=1;
			if(b[i]==0||dfs(b[i])){
			   b[i]=x;
			   return 1;	
			}
		}
	}
	return 0;
}
int main(){
	 ios::sync_with_stdio(0);
	 cin>>n;
	 for(int i=1;i<=n;i++)
	 cin>>a[i];
	 for(int i=1;i<=n;i++)
	 cin>>b[i];
	 for(int i=1;i<=n;i++){
	 	for(int j=1;j<=n;j++){
	 		if(__gcd(a[i],b[j])>1)
	 		match[i][j]=1;
		 }
	 }
	 memset(b,0,sizeof(b));
	 int ans=0;
	 for(int i=1;i<=n;i++){
	 	memset(vis,0,sizeof vis);
	 	if(dfs(i)) ans++;
	 }
	 cout<<ans<<endl;
	 return 0;
}

