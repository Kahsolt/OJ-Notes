#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
int n,k;
void w(int x)
{
	//P
	int tmp;
	if(x>0)
	{
		tmp=x%k;
		if(x/k>0)w(x/k);
	}
	printf("%d",tmp);
}
int main()
{

	while(scanf("%d%d",&k,&n)!=EOF)
	{
		k++;
		w(n);
		printf("\n");
	}

	return 0;
}



