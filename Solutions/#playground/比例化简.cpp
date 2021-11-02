#include<iostream>
using namespace std;
int a,b,l;
int p,q;
double ratio,mingap;
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int main()
{
	while(scanf("%d%d%d",&a,&b,&l)!=EOF)
	{
		ratio=double(a)/double(b);
		mingap=210000000.0;
		for(i,1,l)
		for(j,1,l)
		if(gcd(i,j)==1&&double(double(i)/double(j))>=ratio&&double(double(i)/double(j))-ratio<mingap)
		{
			p=i;q=j;mingap=i/j-ratio;
		}
		printf("%d %d\n",p,q);
	}
	return 0;
}



