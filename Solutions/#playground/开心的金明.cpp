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
//Algorithm
#define max(a,b) a>b?a:b
#define min(a,b) (a<b?a:b)
#define swap(a,b) {a=a^b;b=a^b;a=a^b;}
#define chg(a,b) {a=b-a;b=b-a;a=b+a;}
//Debug
#define D(x) cerr<<""#x"="<<x<<endl;
#define SZ(x) cerr<<"sizof("#x")="<<sizof(x)<<endl;
#define P system("pause");
using namespace std;
int v[30001],w[30001];
int f[30001];
int n,m;
int main()
{
	while(cin>>n>>m)
	{
		for(int i=1;i<=m;i++)
			f[i]=1;
		for(int i=1;i<=m;i++)
			cin>>v[i]>>w[i];
		
		for(int i=1;i<=m;i++)
		for(int j=n;j>=v[i];j--)
		f[j]=max(f[j],f[j-v[i]]+w[i]*v[i]);
		
		cout<<f[n]<<endl;
	}
}



