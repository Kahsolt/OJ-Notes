#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define forr(i, a, b) for(int i=a;i<b;i++)
#define forp(i, a, b) for(int i=a;i<=b;i++)
#define input(x) scanf("%d",&x);
#define inputs(x) scanf("%s",&x); getchar()
#define read(x) int x;input(x)
int cmp(const void* a,const void* b){return strcmp(a, b);}
#define MAXLEN 5000

// 2021/08/16 

char s[MAXLEN+1], **pool;
int cnt = 0, *hash;

int shash(char *s) {
  int h = 0;
  while (*s) {
    h += (*s << 7) + (*s >> 5);
    s++;
  }
  return h;
}

void gen_substrs(int len) {
  forr (i, 0, len-1)
    forr (j, i, len) {
      char tail = s[j+1]; s[j+1] = '\0';  // inplace make string
      //printf("  >> test %s\n", &s[i]);
      
      int h = shash(&s[i]);
      bool found = false;
      forr (k, 0, cnt) {
        if (hash[k] == h && !strcmp(&s[i], pool[k]))
          { found = true; break; }
      }
      if (!found) {
        //printf("  << add %s\n", &s[i]);
        hash[cnt] = h;
        pool[cnt] = malloc(sizeof(char)*(j-i+2)); strcpy(pool[cnt], &s[i]);
        cnt++;
      }
      
      s[j+1] = tail;        // undo
    }
}

int main() {
  inputs(s);
  int len = strlen(s), maxcnt = len*(len-1)/2;
  pool = malloc(sizeof(char*)*maxcnt);
  hash = malloc(sizeof(int)*maxcnt);
  
  gen_substrs(len);
  //forr (k, 0, cnt) puts(pool[k]);
  //printf("len = %d\n", cnt);
  //qsort(pool, cnt, sizeof(char*), cmp);
  forr (i, 0, cnt-1)
    forr (j, i+1, cnt)
      if (strcmp(pool[i], pool[j]) > 0) {
        char *tmp = pool[i];
        pool[i] = pool[j];
        pool[j] = tmp;
      }
  //forr (k, 0, cnt) puts(pool[k]);

  read(k);
  puts(pool[k-1]);
}
