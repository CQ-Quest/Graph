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
	if(n+1==row)//��ʾһ�ַ������� 
	{
		cnt++;
		return;
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]) continue;//�����i���Ѿ����ûʺ󣬾Ͳ����ٷ��� 
		a[i]=row;         //�����i���ܷ� 
	    ok=1;
		for(int j=1;j<=n;j++)   //�жϵ�i���ܲ��ܷ��� 
		{
			if(i==j)  continue; //������Ҫ�ٱȽ� 
			if(!a[j]) continue; //�����j��û�з��ûʺ�, ���i����Ӱ�� 
			if(a[j]-a[i]==j-i||a[j]-a[i]==i-j) //�����Խ��߲�������������ʺ� 
				ok=0;
				break;
			}
		}
		if(ok) dfs(row+1,n);//���԰ѻʺ����һ�� 
		a[i]=0;             //Ҫ�Ѵ�����գ�Ϊ�����ж���һ�ַ��� 
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
