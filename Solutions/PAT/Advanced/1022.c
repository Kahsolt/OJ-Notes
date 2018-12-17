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
#define read(x) int x;scanf("%d",&x)
#define prtl() putchar('\n')
#define prti(x) printf("%d", x)
#define prta(x, a, b) forr(i,a,b){if(i!=a)putchar(' ');prti(x[i]);}
#define N 10000
#define STRLEN 81
#define MOD 10000007
/* Digital Library (30) */
#define NOUSE_HASH

#ifdef USE_HASH
int hash(char* str) {
  int ret = 0;
  while (*str != '\0')
    ret = ((ret << 5) + (ret >> 2) + (*str++)) % MOD;
  return ret;
}
#endif
typedef struct book {
  int ID;
  char title[STRLEN];
  char author[STRLEN];
  char keywords[5][11];   int keywords_cnt;
  char publisher[STRLEN];
  int publish_year;
#ifdef USE_HASH
  int title_hash;
  int author_hash;
  int publisher_hash;
#endif
} Book;
Book books[N], *books_cur = books;
int cmp(const void* a, const void* b) {
  return ((Book*)a)->ID - ((Book*)b)->ID;
}
#ifdef USE_HASH
void prt() {
  puts("======================");
  Book* p = books;
  while (p != books_cur) {
    printf("#%d\n",  p->ID);
    printf("  [%s] : <%d>\n",  p->title, p->title_hash);
    printf("  [%s] : <%d>\n",  p->author, p->author_hash);
    forr(i, 0, p->keywords_cnt)
      printf("    [%s]\n",  p->keywords[i]);
    printf("  [%s] : <%d>\n",  p->publisher, p->publisher_hash);
    printf("  [%d]\n",  p->publish_year);
    p++;
  }
  puts("======================");
}
#endif
int main() {
  read(n); getchar();
  times(n) {
    scanf("%d", &books_cur->ID); getchar();
    gets(books_cur->title);
    gets(books_cur->author);
    char keywords[STRLEN]; gets(keywords);
    char delim = ' ', *tok = strtok(keywords, &delim);
    while (tok) {
      strcpy(books_cur->keywords[books_cur->keywords_cnt++], tok);
      tok = strtok(NULL, &delim);
    }
    gets(books_cur->publisher);
    scanf("%d", &books_cur->publish_year); getchar();
#ifdef USE_HASH
    books_cur->title_hash = hash(books_cur->title);
    books_cur->author_hash = hash(books_cur->author);
    books_cur->publisher_hash = hash(books_cur->publisher);
#endif
    books_cur++;
  }
  qsort(books, n, sizeof(Book), cmp);
  // prt();
   
  read(m); getchar();
  times(m) {
    char type, query[100];
    scanf("%c: %[^\n]s", &type, query); getchar();
    printf("%c: %s\n", type, query);
    int y, h;
    if (type == '5') sscanf(query, "%d", &y);
#ifdef USE_HASH
    else h = hash(query);
#endif
    Book* p = books; bool found = false;
    switch (type) {
      case '1':
        while (p != books_cur) {
          if (
#ifdef USE_HASH
              h == p->title_hash && 
#endif
              !strcmp(query, p->title))
            { printf("%d\n", p->ID); found = true; }
          p++;
        }
        break;
      case '2':
        while (p != books_cur) {
          if (
#ifdef USE_HASH
              h == p->author_hash &&
#endif
            !strcmp(query, p->author))
            { printf("%d\n", p->ID); found = true; }
          p++;
        }
        break;
      case '3':
        while (p != books_cur) {
          forr(i, 0, p->keywords_cnt)
            if (!strcmp(query, p->keywords[i]))
              { printf("%d\n", p->ID); found = true; break; }
          p++;
        }
        break;
      case '4':
        while (p != books_cur) {
          if (
#ifdef USE_HASH
              h == p->publisher_hash && 
#endif
              !strcmp(query, p->publisher))
            { printf("%d\n", p->ID); found = true; }
          p++;
        }
        break;
      case '5':
        while (p != books_cur) {
          if (y == p->publish_year)
            { printf("%d\n", p->ID); found = true; }
          p++;
        }
        break;
    }
    if (!found) puts("Not Found");
  }
}