#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int a[15];    
int method[15];  
int cnt;
void dfs(int row,int n)
{
	int ok,i;
	if(n+1==row)//表示一种方案结束 
	{
		cnt++;
		return;
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]) continue;//如果第i列已经放置皇后，就不能再放置 
		a[i]=row;         //假设第i列能放 
	    ok=1;
		for(int j=1;j<=n;j++)   //判断第i列能不能放置 
		{
			if(i==j)  continue; //本身不需要再比较 
			if(!a[j]) continue; //如果第j列没有放置皇后, 则对i列无影响 
			if(a[j]-a[i]==j-i||a[j]-a[i]==i-j) //两个对角线不允许放置两个皇后 
				ok=0;
				break;
			}
		}
		if(ok) dfs(row+1,n);//可以把皇后放下一行 
		a[i]=0;             //要把此列清空，为了能判断下一种方案 
	}
int main()
{
	int n;
	for(int i=1;i<=10;i++)
	{
		memset(a,0,sizeof(a));
		cnt=0;
		dfs(1,i);
		method[i]=cnt;
	} 
	while(~scanf("%d",&n)&&n)
	   cout<<method[n]<<endl;
	return 0;
}
