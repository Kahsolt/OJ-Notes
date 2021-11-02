#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define forr(i, a, b) for(int i=a;i<b;i++)
int cmp(const void* a,const void* b){return strcmp(a, b);}
#define MAXN 100000
#define MAXLEN 100

// 2021/08/18 

char **a;
int n = 0;

int main() {
  a = malloc(MAXN*sizeof(char*));
  while (1) {
    char c = getchar();
    if (c=='\n' || c==-1) break;

    int p = 0;
    a[n] = malloc(MAXLEN*sizeof(char));
    do { a[n][p++] = c; c = getchar(); }
    while (c != ',' && c != '\n' && c != -1);
    a[n++][p] = '\0';
  }
  
  qsort(a, n, sizeof(char*), cmp);
  //forr (i, 0, n-1)
  //  forr (j, i+1, n)
  //    if (strcmp(a[i], a[j]) > 0) {
  //      char *t = a[i];
  //      a[i] = a[j];
  //      a[j] = t;
  //    }

  forr (i, 0, n)
    printf("%s", a[i]);
}
