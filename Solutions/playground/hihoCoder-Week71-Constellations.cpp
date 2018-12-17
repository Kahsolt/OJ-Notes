#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool sky[1001][1001];
int signX[21][21];
int signY[21][21];
int k,h,w,n,m;
char c;
int main()
{
	memset(sky,0,sizeof(sky));
	memset(signX,0,sizeof(signX));
	memset(signY,0,sizeof(signY));
	
    cin>>k;
    for(int p=1;p<=k;p++)
    {
    	cin>>h>>w;
    	for(int i=1;i<=h;i++)
    	for(int j=1;j<=w;j++)
    	{
    		cin>>c;
    		if(c=='#')
    		{
    			signX[p][++signX[p][0]]=i;
    			signY[p][++signY[p][0]]=j;
			}
		}
	}
	cin>>n>>m;
	for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
   	{
    	cin>>c;
    	if(c=='#')sky[i][j]=1; 
	}
	
	bool flag;
	for(int p=1;p<=k;p++)
	{
		bool exist=false;
		for(int sx=1;sx<=n;sx++)
		for(int sy=1;sy<=m;sy++)
		{
			flag=true;
			for(int q=1;q<=signX[p][0];q++)
			if(sky[sx+signX[p][q]-1][sy+signY[p][q]-1]==0)
			{flag=false;break;}
			if(flag){exist=true;sx=n+1;break;}
		}
		if(exist)printf("Yes\n");
		else printf("No\n");
	}
    return 0;
}

