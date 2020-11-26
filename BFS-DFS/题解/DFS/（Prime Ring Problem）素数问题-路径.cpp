#include<bits/stdc++.h>
using namespace std;
#define maxn 500
bool isprime[maxn],vis[maxn];
int a[maxn];
int n;
void prime()
{
    memset(vis,0,sizeof(vis));
    isprime[0]=isprime[1]=1;
    for(int i=2; i<maxn; i++)
        for(int j=i*i; j<maxn; j+=i)
            isprime[j]=1;
}
void dfs(int step)
{
    if(step>n&&!isprime[a[step-1]+1])
    {
        for(int j=1; j<n; j++)
            cout<<a[j]<<" ";
        cout<<a[n]<<endl;
    }
    for(int i=2; i<=n; i++)
    {
        a[step]=i;
        if(!isprime[a[step]+a[step-1]]&&!vis[i])
        {
            vis[i]=1;
            dfs(step+1);
            vis[i]=0;
        }
    }
}
int main()
{
    prime();
    int cnt =1;
    while(cin>>n)
    {
        cout<<"Case "<<cnt++<<":"<<endl;
        memset(vis,0,sizeof(vis));
        a[1]=1;
        dfs(2);
        cout<<endl;
    }
}
