#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define forr(i, a, b) for(int i=a;i<b;i++)
#define forp(i, a, b) for(int i=a;i<=b;i++)
#define times(n) int _##n=n;while(_##n--)
#define mset(d, v) memset(d,v,sizeof(d))
#define min(a, b) (((a)<=(b))?(a):(b))
#define swap(a, b) (a)^=(b)^=(a)^=(b)
#define input(x) scanf("%d",&x)
#define read(x) int x;input(x)
#define prtl() putchar('\n')
#define prti(x) printf("%d", x)
#define prta(x, a, b) forr(i,a,b){if(i!=a)putchar(' ');prti(x[i]);}
int cmp(const void* a,const void *b){return *((int*)a)-*((int*)b);}
#define N 101
/* The Largest Generation (25) */

bool graph[N][N] = { false };

void toposort(int n) {
  int queue[N], head = 0, rear = 0;
  queue[head++] = 1;  // fixed root node 1
  int robin = head;   // setup robin

  int ans = 1, anslevel = 1, level = 0;
  while (head != rear) {
    int cnt = 0;
    while (rear != robin) {
      int f = queue[rear];
      rear = (rear + 1) % N;
      cnt++;
      forp(s, 1, n) if (graph[f][s]) {
        queue[head] = s;
        head = (head + 1) % N;
      }
    }
    level++;
    if (cnt > ans) { ans = cnt; anslevel = level; }
    robin = head;
  }
  printf("%d %d", ans, anslevel);
}

int main() {
  read(n); read(m); times(m) {
    read(f); read(k); times(k) {
      read(s); graph[f][s] = true;
    }
  }
  toposort(n);
}