#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
#define dbg(x) cout<<x;
using namespace std;
int main()
{
	int m,n;
	int f[101][101],v[101][101]={0};
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	for(int j=1;j<=n;j++)
	{cin>>f[i][j];v[i][j]=1;}
	
	for(int i=1;i<=n;i++)
	{
		int j=1,tmp=i;
		while(j<=m&&tmp>=1)
		{
			cout<<f[j][tmp]<<endl;
			j++;tmp--;
		}
	}
	for(int j=2;j<=m;j++)
	{
		int a=j,b=n;
		while(a<=m&&b>=1)
		{
			cout<<f[a][b]<<endl;
			a++;b--;
		}
	}
	return 0;
}

