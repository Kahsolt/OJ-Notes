#include <stdio.h>
#define MAXN 10

char m[319683][512] = { 0 };      // 1 for ' ', 2 for 'x'

typedef struct point {
    int x, y;
} Point;

void print(Point p) {
    //printf("p = (%d, %d)\n", p.x, p.y);
}
void copy1(Point src, Point dst, int h, int w) {
    for (int i=0; i<h; i++)
        for (int j=0; j<w; j++)
            m[dst.x+i][dst.y+j] = m[src.x+i][src.y+j] == 2 ? 2 : 1;
}

void copy4(Point lu, Point rb) {
    int h = rb.x - lu.x + 1,
        w = rb.y - lu.y + 1;
    //printf("h = %d, w = %d\n", h, w);
    Point dst;
    dst.x = lu.x - h; dst.y = lu.y + w;
    print(dst);
    copy1(lu, dst, h, w);
    dst.x = lu.x - h; dst.y = lu.y;
    print(dst);
    copy1(lu, dst, h, w);
    dst.x = lu.x + h; dst.y = lu.y;
    print(dst);
    copy1(lu, dst, h, w);
    dst.x = lu.x + h; dst.y = lu.y + w;
    print(dst);
    copy1(lu, dst, h, w);
}

int main() {
    int n; scanf("%d", &n);
    int X = 319683 / 2, Y = 0;
    m[X][Y] = 2;
    int H = 1, W = 1;
    for (int i=1; i<n; i++) {
        Point lu; lu.x = X - H / 2; lu.y = 0;
        Point rb; rb.x = X + H / 2; rb.y = W-1;
        copy4(lu, rb);
        H *= 3; W *= 2;
    }
    //printf("H = %d, W = %d\n", H, W);
    //puts("============");
    Point lu; lu.x = X - H / 2; lu.y = 0;
    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++)
            if (m[lu.x+i][lu.y+j] == 1)
                putchar(' ');
            else if (m[lu.x+i][lu.y+j] == 2)
                putchar('x');
        if (i != H) putchar('\n');
    }
    //puts("============");
}