#include <cstdio>
#include <cstring>
#define MAX 100001
int f[MAX],k[16];
int n,m;
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset(f,0,sizeof(f));
        for(int i=1; i<=m; i++)
			scanf("%d",&k[i]);

        for(int i=1;i<=n;++i)
            for (int j=1;j<=m;++j)
            {
                if (i>=k[j]&&!f[i-k[j]])
                {
                    f[i]=1;	//sign of firsthand
                    break;
                }
			}
        if(f[n])
            printf("sente\n");
        else
            printf("gote\n");
    }
    return 0;
}
