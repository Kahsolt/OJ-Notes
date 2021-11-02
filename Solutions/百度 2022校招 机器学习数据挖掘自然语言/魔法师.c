#include <stdio.h>
#define MAXN 100000
#define INF 0x3F3F3F3F

/*
5
1 2 3 4 5
2 3 4 5 6

6
1 8 3 6 7 5
1 2 3 6 9 7

6
1 8 3 6 7 5
1 2 3 6 9 8
*/

int A[MAXN], B[MAXN];
int N;

int backtrack(int i, int cost) {
    //printf("i=%d cost=%d\n", i, cost);

    if (i == N) return cost;
    
    int c1 = INF, c2 = INF, c3 = INF;
    // 如果原始的A不递增了
    if (A[i-1] >= A[i]) {
        // 也没办法替换，就完蛋
        //printf("i=%d [%d,%d]\n", i, A[i-1], A[i]);
        if (A[i-1] >= B[i]) return INF;
        // 替换试试
        else {
            if (A[i-1] < B[i]) {
                //puts("try c1");
                int tmp = A[i];
                A[i] = B[i];
                c1 = backtrack(i+1, cost+1);
                A[i] = tmp;
            }
        }
    }
    else {
        // 不替换试试
        //puts("try c2");
        c2 = backtrack(i+1, cost);
        //printf("c2=%d\n", c2);
        // 也可以替换试试
        if (B[i] < A[i]) {
            //puts("try c3");
            int tmp = A[i];
            A[i] = B[i];
            c3 = backtrack(i+1, cost+1);
            A[i] = tmp;
        }
    }

    //printf("i=%d, c=(%d, %d, %d)\n", i, c1, c2, c3);
    int r = c1 <= c2 ? c1 : c2;
    r = c3 <= r ? c3 : r;
    return r;
}

int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", &A[i]);
    for (int i=0; i<N; i++) scanf("%d", &B[i]);

    int cost = backtrack(1, 0);
    printf("%d\n", cost == INF ? -1 : cost);
}
