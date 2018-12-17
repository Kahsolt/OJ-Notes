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
void QuickSort(DataType *seq,int left,int right)
{
	int x=left,y=right,mid=seq[(left+right)>>1];
	do{while(seq[x]<mid)x++;while(seq[y]>mid)y--;if(x<=y){swap(seq[x],seq[y]);x++;y--;}}while(x<=y);
	if(left<y)QuickSort(seq,left,y);
	if(x<right)QuickSort(seq,x,right);
}
string str; 
int main()
{
	while(cin>>str)
	{
		if(str[2]=='0'&&str[3]=='6')cout<<"SCSE"<<endl;
		else if(str[2]=='2'&&str[3]=='1')cout<<"SOFT"<<endl;
		else cout<<"OTHER"<<endl;
	}
	return 0;
}



