#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
 
int n;
int per[100000]; 
double x[200],y[200];
 
struct node{
	int u,v;
	double w;    //w为距离 
}s[100000];
 
bool cmp(node a,node b){
	return a.w<b.w;
}
int find(int x){
	int k,j,r;
	r=x;
	while(r!=per[r]) r=per[r];
	k=x;
	while(k!=r){
		j=per[k];
		per[k]=r;
		k=j;
	}
	return r;
}
 
bool merge(int a,int b)    {
	int x=find(a);
	int y=find(b);
	if(x!=y){
		per[x]=y;
		return 1;
	}
	return 0;
}
 
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;++i){
			scanf("%lf%lf",&x[i],&y[i]);
		     per[i]=i;
		}
		int cnt=0;
		for(int i=0;i<n-1;++i){
			for(int j=i+1;j<n;++j)
			{
				double d=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
				if(d>=10&&d<=1000)
				{
					s[cnt].u=i; 
					s[cnt].v=j; 
					s[cnt].w=d;
					cnt++;
				}
			}
		}
		sort(s,s+cnt,cmp);   
		
		int flag=0;
		double sum=0;
		
		for(int i=0;i<cnt;++i){
			if(merge(s[i].u,s[i].v))  {
				sum+=s[i].w;
				flag++;   //已连的路数 
			}
		}
		
		if(flag==n-1)   
			printf("%.1lf\n",sum*100);
		else  puts("oh!");	
	}
	return 0;
}
