#include<iostream>
#include<cstdio>
#include<memory>
using namespace std;
#define maxLength 100

int f[maxLength+1][maxLength+1];
int s[maxLength+1][maxLength+1];
int x[maxLength+1];
int n;

int matrixChain(int x[],int f[][],int s[][]) {
	memset(m,0,sizeof(m));
	for(int r=2;r<=n;r++)
    for(int i=1;i<=n-r+1;i++) {
      int j=i+r-1;
      m[i][j]=m[i-1][j]+p[i-1]*p[i]*p[j];
      s[i][j]=i;
      for(int k=i+1;k<j;k++)
      {
        int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
        if(t<m[i][j])
        {
          m[i][j]=t;
          s[i][j]=k;
        }
      }
    }
}
void display()
{
	for(int i=1;i<=n;i++)
	cout<<i<<" ";
	cout<<endl<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<i;
		for(int j=1;j<=n;j++)
		cout<<s[i][j]<<" ";
		cout<<endl;
	}
}
