#include <stdio.h>
#include <stdbool.h>
#define MAXN 1000
#define MAXR 10
#define MAXC 9

/*
4 2 2 5
0 1 8 4
*/

typedef struct point { int x, y; } Point;
typedef struct state { int x, y, step; } State;

int dx[] = {-2,-3,+2,+3,-2,-3,+2,+3},
    dy[] = {-3,-2,-3,-2,+3,+2,+3,+2};
bool board[MAXR][MAXC] = { 0 };       // visit mark
State q[MAXN];
int q_head = 0, q_rear = 0;

static inline bool chk(int x, int y) { return 0 <= x && x < MAXR && 0 <= y && y < MAXC; }

int main() {
    Point xiang, jiang;
    scanf("%d%d", &xiang.x, &xiang.y);
    scanf("%d%d", &jiang.x, &jiang.y);
    if (xiang.x == jiang.x && xiang.y == jiang.y) {
        puts("0");
        return 0;
    }
    
    board[xiang.x][xiang.y] = 1;
    State s; s.x = xiang.x, s.y = xiang.y, s.step = 0;
    q[q_rear++] = s;

    // bfs
    while (q_head != q_rear) {
        State s = q[q_head++];
        for (int d=0; d<8; d++) {
            int nx = s.x + dx[d],
                ny = s.y + dy[d]; 
            if (!board[nx][ny] && chk(nx, ny)) {
                if (nx == jiang.x && ny == jiang.y) {
                    printf("%d\n", s.step + 1);
                    goto OK;
                }
                board[nx][ny] = 1;

                State ns; ns.x = nx, ns.y = ny, ns.step = s.step + 1;
                q[q_rear++] = ns;
            }
        }
    }
FAIL:
    puts("-1");
OK:
    return 0;
}