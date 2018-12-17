#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,x,bit;
int f[33];
int main()
{
    memset(f,0,sizeof(f));
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        for(int j=1;j<=32;j++)
        {
            bit=(unsigned(~0)>>31)&x;
            f[j]+=bit;
            x=x>>1;
        }
    }
    for(int i=1;i<=32;i++)
        f[i]%=3;
    unsigned int ans=0;
    for(unsigned int i=1;i<=32;i++)
    if(f[i]==1)
    {
    	unsigned tmp=unsigned((unsigned(~0)>>31)<<(i-1));
    	ans+=tmp;
	}
    cout<<ans<<endl;
    return 0;
}
