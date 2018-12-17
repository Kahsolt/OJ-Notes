#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,T,v[20001];
bool f[20001];
int main()
{
    memset(f,0,sizeof(f));
    cin>>T>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=T;j++)
            if(f[j]==1&&j+v[i]<=T)f[j+v[i]]=1;
        if(v[i]<=T)f[v[i]]=1;
    }
    /*
    for(int j=1;j<=T;j++)
    	cout<<f[j]<<" ";
    	cout<<endl;
    */
    int k;
    for(k=T;k>=1;k--)
        if(f[k]==1)break;
    cout<<T-k<<endl;
    return 0;
}
