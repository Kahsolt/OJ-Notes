#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;
class Segment
{
	public:
		double X1,Y1,X2,Y2;
		Segment(double xx1,double yy1,double xx2,double yy2)
		{
			X1=xx1;Y1=yy1;
			X2=xx2;Y2=yy2;
		}
};
bool isCrux(Segment *A,Segment *B)
{
	double left,right;
	//use A to test B
	left=B->X1*(A->Y1-A->Y2)-B->Y1*(A->X1-A->X2)+A->X1*A->Y2-A->Y1*A->X2;
	right=B->X2*(A->Y1-A->Y2)-B->Y2*(A->X1-A->X2)+A->X1*A->Y2-A->Y1*A->X2;
	if(left*right>0)return false;
	//use B to test A
	left=A->X1*(B->Y1-B->Y2)-A->Y1*(B->X1-B->X2)+B->X1*B->Y2-B->Y1*B->X2;
	right=A->X2*(B->Y1-B->Y2)-A->Y2*(B->X1-B->X2)+B->X1*B->Y2-B->Y1*B->X2;
	if(left*right>0)return false;
	
	return true;
}
int n;
double xx1,yy1,xx2,yy2;
Segment *seg[100001];
bool Crux[100001];
int main()
{
	while(~scanf("%d",&n))
	{
		memset(Crux,0,sizeof(Crux));
		for(int i=1;i<=n;i++)
		{
			scanf("%lf%lf%lf%lf",&xx1,&yy1,&xx2,&yy2);
			seg[i]=new Segment(xx1,yy1,xx2,yy2);
		}
		/*
		for(int i=1;i<=n;i++)
		{
			D(seg[i]->X1);
			D(seg[i]->Y1);
			D(seg[i]->X2);
			D(seg[i]->Y2);
		}
		*/
		for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
		{
			if(isCrux(seg[i],seg[j]))
			Crux[min(i,j)]=true;
		}
		
		for(int i=1;i<=n;i++)
		if(!Crux[i])printf("%d ",i);
		printf("\n");
	}
	return 0;
}
