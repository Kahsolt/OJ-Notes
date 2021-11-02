#include <stdio.h>
#include <string.h>
#define MAXN 5000
#define min(a,b) ((a) <= (b) ? (a) : (b))

/*
5
0 1 1 2 0
0 1 1 1 0
1 0 0 0 3
1 0 0 0 1
1 0 0 0 1
0 3 1 1 0
*/


int n;
int cost[MAXN] = { 0 };
int m[MAXN][MAXN] = { 0 };

int mindist[MAXN] = { 0 };
char flag[MAXN] = { 0 };    // vis[]

int dijkstra() {
    for (int i=0; i<n; i++) mindist[i] = m[0][i];
    flag[0] = 1;            // starts from 0, targets for n-1
    mindist[0] = 0;

    for (int T=1; T<n; T++) {
/*
        puts("mindist[i]: ");
        for (int i=0; i<n; i++)
            printf("%d ", mindist[i]);
        putchar(10);
*/
        int idx = -1, min = 0x3F3F3F3F;
        for (int i=0; i<n; i++)
            if (!flag[i] && mindist[i] > 0 && mindist[i] < min)
                    min = mindist[idx = i];

        flag[idx] = 1;

        for (int j=0; j<n; j++)
            if (!flag[j] && m[idx][j] > 0)
                mindist[j] = min(mindist[j], mindist[idx] + m[idx][j]);
    }
    
    return mindist[n-1];
}
int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++)
        scanf("%d", &cost[i]);
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++) {
            scanf("%d", &m[i][j]);
            m[i][j] += cost[i];
        }
    
    printf("%d", dijkstra());
}