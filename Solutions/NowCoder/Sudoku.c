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
int cmp(const void* a,const void* b){return *((int*)a)-*((int*)b);}
#define DTYPE int
#define N 9
#define TARGET 45

// 2021/08/11 

/*
0 9 2 4 8 1 7 6 3
4 1 3 7 6 2 9 8 5
8 6 7 3 5 9 4 1 2
6 2 4 1 9 5 3 7 8
7 5 9 8 4 3 1 2 6
1 3 8 6 2 7 5 9 4
2 7 1 5 3 8 6 4 9
3 8 6 9 1 4 2 5 7
0 4 5 2 7 6 8 3 1
*/

// data struct
DTYPE board[N+1][N+1] = { 0 };  // board[0][j] for sum(col), board[0][j] for sum(row);
DTYPE block[3][3] = { 0 };
bool found = false;

typedef struct trials {
  DTYPE cnt;
  DTYPE* vals;
} Trial;

typedef struct vacant {
  int r, c;
  struct vacant *next;
} Vacant;

Vacant* vacants = NULL;

// debug
void show_board() {
  printf("Board: \n");
  forp (i, 0, N) {
    forp (j, 0, N)
      printf("%d ", board[i][j]);
    prtl();
  }
}
void show_block() {
  printf("Block: \n");
  forr (i, 0, 3) {
    forr (j, 0, 3)
      printf("%d ", block[i][j]);
    prtl();
  }
}
void show_vacants() {
  printf("Vacants: ");
  Vacant* v = vacants;
  while (v) {
    printf("(%d, %d) ", v->r, v->c);
    v = v->next;
  }
  prtl();
}
void show_trail(Trial* t) {
  printf("%d: {", t->cnt);
  forr (i, 0, t->cnt)
    printf("%d ", t->vals[i]);
  puts("}");
}
void show_flag(bool flag[]) {
  printf("flag: ");
  forp (i, 1, N) printf("%d ", flag[i]);
  putchar('\n');
}

// utils
static inline int block_idx(int idx) {
  return (idx - 1) / 3;
}

Trial* new_trail(int n) {
  Trial* t = (Trial*) malloc(sizeof(Trial));
  t->cnt = n;
  if (n) t->vals = (DTYPE*) malloc(sizeof(DTYPE)*n);
  return t;
}

void free_trail(Trial* trail) {
  if (trail) {
    if (trail->vals) free(trail->vals);
    free(trail);
  }
}

Trial* get_trail(int r, int c) {
  bool flag[N+1] = { false };
  
  // mark used in row & column
  forp (i, 1, N) flag[board[r][i]] = flag[board[i][c]] = true;
  //show_flag(flag);

  // mark used in block
  int br = block_idx(r) * 3, bc = block_idx(c) * 3;
  forr (i, 1, 3)
    forr (j, 1, 3)
      flag[board[br+i][bc+j]] = true;
  //show_flag(flag);

  // cnt trails  
  int cnt = 0;
  forp (i, 1, N) if (!flag[i]) cnt++;

  // make trail
  Trial* t = new_trail(cnt);
  int idx = 0;
  forp (i, 1, N)
    if (!flag[i])
      t->vals[idx++] = i;

  return t;
}

void add_trail(int r, int c) {
  Vacant* v = (Vacant*) malloc(sizeof(Vacant));
  v->r = r; v->c = c;
  v->next = vacants; vacants = v;
}

bool check() {
  // check rows & lines
  forp (k, 1, N)
    if (board[k][0] != TARGET || board[0][k] != TARGET)
      return false;

  // check blocks
  forr (i, 0, 3)
    forr (j, 0, 3)
      if (block[i][j] != TARGET)
        return false;

  // check passed
  return true;
}

void search(Vacant* v) {
  if (!v) {
    if (check()) found = true;
    return;
  }

  Trial* t = get_trail(v->r, v->c);
  //printf(" try fill (%d, %d), trails: ", v->r, v->c); show_trail(t);
  for (int i=0; !found && i<t->cnt; i++) {
    int x = t->vals[i];
    board[v->r][v->c] = x;
    board[0][v->c] += x; board[v->r][0] += x;
    block[block_idx(v->r)][block_idx(v->c)] += x;
    search(v->next); if (found) return;
    board[v->r][v->c] = 0;
    board[0][v->c] -= x; board[v->r][0] -= x;
    block[block_idx(v->r)][block_idx(v->c)] -= x;
  }
  //free_trail(t);
}

// main
int main() {
  forp (i, 1, N)
    forp (j, 1, N) {
      read(x); board[i][j] = x;
      if (!x) add_trail(i, j);
      else {
        board[i][0] += x; board[0][j] += x;
        block[block_idx(i)][block_idx(j)] += x;
      }
    }
  
  //show_board(); show_block(); show_vacants();
  
  search(vacants);
  //puts("Search done.");

  if (!found) puts("No solution!");
  else 
    forp (i, 1, N) {
      forp (j, 1, N) {
        prti(board[i][j]);
        putchar(' ');
      }
      prtl();
    }
}
