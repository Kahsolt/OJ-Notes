#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

// 2018/08/01

int set[N];
int root(int x) {
  return x!=set[x] ? set[x]=root(set[x]) : x;
} 
void merge(int x, int y) {
  set[root(x)] = set[root(y)];
}
void prt() {
  for(int i=0; i<N; i++)
    printf("%d ", i);
  printf("\n");
  for(int i=0; i<N; i++)
    printf("%d ", root(i));
  printf("\n");
}

int main() {
  for(int i=0; i<N; i++) set[i] = i;
  
  srand(time(NULL));
  int t = rand() % N + 1;
  while (t--) {
    int x, y;
    do {
      x = rand() % N;
      y = rand() % N;
    } while (x == y);
    printf("merge %d and %d\n", x, y);
    merge(x, y);
    prt();
  }
}