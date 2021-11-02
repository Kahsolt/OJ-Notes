#include <stdio.h>
#include <stdlib.h>
#define MAXN 100000

/*
5
20 5
30 10
25 8
15 15
10 6
*/

int N;
int ans = -1;
typedef struct mono { int w, v; } Mono;
Mono x[MAXN];

int cmp(const void* a, const void* b) {
    Mono *pa = (Mono*) a, *pb = (Mono*) b;
    if (pa->w == pb->w) return pb->v - pa->v;
    else return (pa->w - pb->w);
}

void backtrack(int i, int now, int val) {
    if (i == N) {
        //printf("find a solution of value: %d\n", val);
        if (val > ans) ans = val;
        return;
    }

    // just skip x[i] 
    backtrack(i+1, now, val);
    // try add x[i]
    if (now + 10 <= x[i].w)
        backtrack(i+1, now + 10, val + x[i].v);
}

int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d%d", &x[i].w, &x[i].v);
    
    //for (int i=0; i<N-1; i++)
    //    for (int j=i+1; j<N; j++)
    //        if (cmp(&x[i], &x[j])) {
    //            Mono t = x[i];
    //            x[i] = x[j];
    //            x[j] = t;
    //        }
    qsort(&x, N, sizeof(Mono), cmp);

    //puts("======");
    //for (int i=0; i<N; i++) printf("%d %d\n", x[i].w, x[i].v); putchar(10);
    //puts("======");
    backtrack(0, 0, 0);
    printf("%d\n", ans);
}