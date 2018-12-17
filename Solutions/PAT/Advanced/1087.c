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
#define INF 0x3F3F3F
#define HASH 26*26*26
#define NSTR 4
#define N 200
#define M N*(N-1)
/* All Roads Lead to Rome (30) */

// city names are numbers that based in 26
#define hash(str) (*str - 'A') \
  + (*(str + 1) - 'A') * 26 \
  + (*(str + 2) - 'A') * 26 *26
int id[HASH], id_cur = -1;  // mapping 'AAA'~'ZZZ' to 0~(n-1)
char names[N][NSTR]; // inv mapping of id[]

int graph[N][N], happiness[N] = { 0 };  // the cost and happiness
int path[N];  // shortest path with min hops record

void prt_path(int D) {
  if (D != path[D]) {
    prt_path(path[D]);
    printf("->%s", names[D]);
  }
  else printf("%s", names[D]);
}
void djikstra(int n, int S, int D) {
  bool vis[N] = { false };
  int* dis = malloc(n * sizeof(int)); // dp[] for min cost
  int* hap = malloc(n * sizeof(int)); // dp[] for max happiness
  int* cnt = malloc(n * sizeof(int)); // dp[] for shortest path count
  int* hop = malloc(n * sizeof(int)); // dp[] for min hop
  forr(i, 0, n) {
    dis[i] = graph[path[i] = S][i];
    hap[i] = happiness[i];
    bool iso = dis[i]==INF;
    cnt[i] = iso ? 0 : 1;
    hop[i] = iso ? INF : 1;
  }
  dis[S] = hap[S] = hop[S] = 0;
  cnt[S] = 1; vis[S] = true;

  forr(r, 1, n) { // n-1 round
    int mindis = INF, idx = -1;
    forr(i, 0, n)
      if (!vis[i] && dis[i] < mindis)
        mindis = dis[idx = i];
    vis[idx] = true;

    forr(i, 0, n) if (!vis[i]) {
      if (dis[i] > dis[idx] + graph[idx][i]) {
        dis[i] = dis[idx] + graph[idx][i];  // replace
        cnt[i] = cnt[idx];
        hap[i] = hap[idx] + happiness[i];
        hop[i] = hop[idx] + 1;
        path[i] = idx;
      } else if (dis[i] == dis[idx] + graph[idx][i]) {
        cnt[i] += cnt[idx];     // equal, add on
        int rhap = hap[idx] + happiness[i]; // if detour
        int rhop = hop[idx] + 1;
        if (hap[i] < rhap || hap[i] == rhap
              && (rhap * hop[i] > rhop * hap[i])) {  // larger avg happiness
          hap[i] = hap[idx] + happiness[i];
          hop[i] = hop[idx] + 1;
          path[i] = idx;
        }
      }
    }
  }
  
  printf("%d %d %d %d\n",
    cnt[D], dis[D], hap[D], hap[D] / hop[D]);
  prt_path(D);

  free(dis); free(hap); free(cnt); free(hop);
}

int main() {
  mset(id, 0xFF); mset(graph, INF);
  read(n); read(k); char name[NSTR]; scanf("%s", name); getchar();
  id[hash(name)] = ++id_cur;  // allocate id 0
  strcpy(names[id_cur], name);
  forr(i, 1, n) {
    scanf("%s", name);
    input(happiness[id[hash(name)] = ++id_cur]); // allocate id 1~(n-1)
    strcpy(names[id_cur], name);
    getchar();
  }
  int S = 0, D = id[hash("ROM")]; // S=0 is a trick
  times(k) {
    scanf("%s", name); int from = id[hash(name)];
    scanf("%s", name); int to = id[hash(name)];
    read(c); getchar();
    graph[from][to] = graph[to][from] = c;
  }
  djikstra(n, S, D);
}