#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define DatalLen 1000
#define P system("pause");
#define D(x) cerr<<""#x"="<<x<<endl;

using namespace std;
unsigned char a[DatalLen+1],b[DatalLen+1],c[DatalLen+5];
unsigned char tmp;
unsigned int n,lena,lenb,lenc;

void Plus()
{
	memset(c,0,sizeof(c));
	int k=0;	//shift
	
	int i=lena,j=lenb;
	for(;j>=1&&i>=1;j--,i--)
	{
		c[++k]+=(b[j]+a[i]);
		c[k+1]+=(c[k]/10);
		c[k]=c[k]%10;
	}
	
	if(i>=1)
	{
		while(i>=1)
		{
			c[++k]+=a[i];
			c[k+1]+=(c[k]/10);
			c[k]=c[k]%10;
			i--;
		}
	}
	else
	{
		while(j>=1)
		{
			c[++k]+=b[j];
			c[k+1]+=(c[k]/10);
			c[k]=c[k]%10;
			j--;
		}
	}
	
	lenc=1004;
	while(c[lenc]==0&&lenc>=1)lenc--;
}
int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	 
	{
		lena=lenb=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		while(~scanf("%c",&tmp))
		{
			if(tmp==' ')break;
			a[++lena]=tmp-'0';
		}
		while(~scanf("%c",&tmp))
		{
			if(tmp=='\n')break;
			b[++lenb]=tmp-'0';
		}
		
		Plus();
		
		if(lenc==0)printf("0\n");
		else 
		{
			for(int i=lenc;i>=1;i--)
			printf("%d",int(c[i]));
			printf("\n");
		}
	}
	return 0;
}

void Multiply() {
	memset(c,0,sizeof(c));
	int k=0;
	for(int j=lenb;j>=1;j--) {
		k++;	//Shift
		for(int i=lena;i>=1;i--) {
			c[k+(lena-i)]+=(b[j]*a[i]%10);
			c[k+(lena-i)+1]+=(b[j]*a[i]/10);
			
			c[k+(lena-i)+1]+=(c[k+(lena-i)]/10);
			c[k+(lena-i)]=(c[k+(lena-i)]%10);
		}
	}
	
	lenc=2000;
	while(c[lenc]==0)lenc--;
}
int main() {
	scanf("%d%c",&n,&tmp);
	while(n--)
	{
		lena=lenb=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		while(~scanf("%c",&tmp))
		{
			if(tmp==' ')break;
			a[++lena]=tmp-'0';
		}
		while(~scanf("%c",&tmp))
		{
			if(tmp=='\n')break;
			b[++lenb]=tmp-'0';
		}
		
		if(a[1]==0||b[1]==0)
		{
			printf("0\n");
			continue;
		}
		
		Multiply();
		
		for(int i=lenc;i>=1;i--)
			//cout<<int(c[i]);
			printf("%d",c[i]);
		printf("\n");
	}
	return 0;
}
