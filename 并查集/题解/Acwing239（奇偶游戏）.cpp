#include<bits/stdc++.h>
using namespace std;
const int maxn=40010;
int f[maxn],Base=maxn/2;
unordered_map<int,int>r;
int n,m,k;
int find(int x){
	if(f[x]!=x) {
	f[x]=find(f[x]);
    }
	return f[x];
}
void init(){
	for(int i=0;i<maxn;i++){
		f[i]=i;
	}
}
int get(int x){
	if(r.count(x)==0) r[x]=++n;
	return r[x]; 
}
int main(){
ios::sync_with_stdio(0);
  cin>>n>>m;
  n=0;
  init();
  int ans=m;
  for(int i=1;i<=m;i++){
  	int a,b;
  	string s;
  	cin>>a>>b>>s;
  	a=get(a-1);
  	b=get(b);
  	if(s=="odd"){
  		if(find(a)==find(b)){
  			ans=i-1;
  			break;
		  }
		f[find(a+Base)]=find(b);
		f[find(a)]=find(b+Base); 
	  }
	  else {
	  	if(find(a+Base)==find(b)){
	  		ans=i-1;
	  		break;
		  }
		  f[find(a+Base)]=find(b+Base);
		  f[find(a)]=find(b);
	  }
	  
  }
  cout<<ans<<endl;
  return 0;
}
