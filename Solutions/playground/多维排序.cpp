#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
//DataType
#define DataType int
//Const
#define inf 2147483647
#define esp 1e-8
#define pi 3.14159265358979
#define e 2.71828182845904
#define mod 1000007
//Graph
#define dlt dx[]={1,0,-1,0},dy[]={0,1,0,-1};
#define dir dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,1,0,-1,1,-1,1,-1};
//Function
#define mset(a,b) memset(a,b,sizeof(a));
#define mcpy(d,s) memcpy(d,s,sizeof(s)+1);
#define for(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define defor(i,b,a) for(int i=b;i>=a;i--)
//Algorithm
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define swap(a,b) {a=a^b;b=a^b;a=a^b;}
#define chg(a,b) {a=b-a;b=b-a;a=b+a;}
//Debug
#define D(x) cerr<<""#x"="<<x<<endl;
#define SZ(x) cerr<<"sizof("#x")="<<sizof(x)<<endl;
#define P system("pause");
using namespace std;
int n;
int x[1001],y[1001],z[1001],sum[1001],id[1001];
void Sort()
{
	for(i,1,n-1)
	for(j,i+1,n)
	{
		if(sum[i]<sum[j])
		{swap(sum[i],sum[j]);swap(x[i],x[j]);swap(y[i],y[j]);swap(z[i],z[j]);swap(id[i],id[j]);}
		if(sum[i]==sum[j])
		{
			if(x[i]<x[j]){swap(sum[i],sum[j]);swap(x[i],x[j]);swap(y[i],y[j]);swap(z[i],z[j]);swap(id[i],id[j]);}
			else if(x[i]==x[j]&&i>j){swap(sum[i],sum[j]);swap(x[i],x[j]);swap(y[i],y[j]);swap(z[i],z[j]);swap(id[i],id[j]);}
		}
	}
}
void Print()
{
	for(i,1,5)
	printf("%d %d\n",id[i],sum[i]);
}
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		for(i,1,n)
		{
			scanf("%d%d%d",&x[i],&y[i],&z[i]);
			sum[i]=x[i]+y[i]+z[i];
			id[i]=i;
		}
		Sort();
		Print();
	}

	return 0;
}



