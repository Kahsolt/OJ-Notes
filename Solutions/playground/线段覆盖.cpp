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
int n,p,q;
int a,b;
bool t[400001];
int main()
{
	while(scanf("%d%d%d",&n,&p,&q)!=EOF)
	{
		mset(t,0);
		for(i,1,n)
		{
			scanf("%d%d",&a,&b);
			for(i,a,b)
			t[i]=1;
		}
		bool flag=false;
		for(i,p,q)
		if(t[i]==0)
		{printf("%d\n",i);flag=true;break;}
		if(!flag)printf("War,war never changes.\n");
	}

	return 0;
}



