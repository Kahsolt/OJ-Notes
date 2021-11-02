#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
//Debug
#define esp 1e-8
#define D(x) cerr<<""#x"="<<x<<endl;
#define SZ(x) cerr<<"sizof("#x")="<<sizof(x)<<endl;
#define P system("pause");
using namespace std;
int n,m,my;
bool card[10001];
int main()
{
	while(~scanf("%d%d",&m,&n))
	{
		memset(card,0,sizeof(card));
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&my);
			card[my]=1;
		}
		
		int cnt=0;
		int ans=0;
		int p=m*n;
		while(p>=1)
		{
			if(card[p]==1)cnt++;
			else cnt--;
			if(cnt==1){ans++;cnt=0;}
			p--;
		}
		printf("%d\n",ans);
	}
	return 0;
}
