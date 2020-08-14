#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#define P system("pause");
#define D(x) cerr<<""#x"="<<x<<endl;
using namespace std;
int n,m,h,r;
int d[100001];
int Ans=0;
void Sort(int left,int right)
{
	int x=left,y=right,key=d[(left+right)>>1];
	do{
		while(d[x]<key)x++;
		while(d[y]>key)y--;
		if(x<=y)
		{
			int tmp=d[x];
			d[x]=d[y];
			d[y]=tmp;
			x++;y--;
		}
	}while(x<=y);
	if(left<y)Sort(left,y);
	if(x<right)Sort(x,right);
	return;
}
void Work()
{
	int k=0;
	for(int i=1;i<=n;i++)
	if(d[i]>h+r)break;
	else
	{
		D(i)
		if(d[i]-d[i-1]<=m)k++;
		else
		{
			D(k)
			if(k>Ans)Ans=k;
			k=0;
			
		}
		if(k>Ans)Ans=k;
	}
	
	return;
}
int main()
{
	cin>>n>>m>>h>>r;
	for(int i=1;i<=n;i++)
		cin>>d[i];
	Sort(1,n);	
	d[0]=d[1];
	Work();
	cout<<min(Ans+1,h)<<endl;
	return 0;
}

