#include <stdio.h>
#include <stdbool.h>
#include <memory.h>
#define forr(i, a, b) for(int i=a;i<b;i++)
#define times(n) int _##n=n;while(_##n--)
#define mset(d, v) memset(d,v,sizeof(d))
#define N 26

int graph[N][N];  // default 0: not connected
int main() {
  int n, m; while (~scanf("%d%d", &n, &m)) {
    getchar(); mset(graph, 0x00);
    times(n) {
      char buf[4]; gets(buf);
      int s = buf[0] - 'A',
          f = buf[1] - 'A',
          m = buf[2] - 'A';
      
      static const int NUL = '-' - 'A';
      if (f != NUL) {
        graph[f][s] =  1; // parents are one genration higher
        graph[s][f] = -1; // child is one genration lower
      }
      if (m != NUL) {
        graph[m][s] =  1;
        graph[s][m] = -1;
      }
    }

    forr(k, 0, N) // floyd
      forr(i, 0, N)
        forr(j, 0, N)
          if (i!=j && j!=k && k!=i 
              && graph[i][k] && graph[k][j] && !graph[i][j]
              && (graph[i][k] > 0 && graph[k][j] > 0) 
                || (graph[i][k] < 0 && graph[k][j] < 0))
            graph[i][j] = graph[i][k] + graph[k][j];
    
    times(m) {
      char buf[3]; gets(buf);
      int res = graph[buf[0]-'A'][buf[1]-'A'];
      
      bool sign;  // used in default: case
      switch (res) {
        case  0:  puts("-");            break;
        case  1:  puts("parent");       break;
        case -1:  puts("child");        break;
        default:
          sign = res < 0;
          if (sign) res = -res; res -= 2;
          times (res) printf("great-");
          puts(sign ? "grandchild" : "grandparent");
          break;
      }
    }
  }
}