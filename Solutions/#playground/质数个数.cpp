#include<cstdio>
#include<cstring>
using namespace std;
int p[10000001];
int n;
int main()
{
	memset(p,1,sizeof(p));
	p[0]=p[1]=0;
	for(int i=2;i<=10000000;i++)
	if(p[i]==1)
	{
		int k=2;
		while(i*k<=10000000)
		{
			p[i*k]=0;
			k++;
		}
	}
	for(int i=3;i<=10000000;i++)
	p[i]+=p[i-1];
		
	while(~scanf("%d",&n))
	printf("%d\n",p[n]);
}
