#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
// #include <ctype.h>
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
#define NSTR (1048576+1)
#define MOD 100007
/* Speech Patterns (25) */

typedef struct token {
  char *val;
  int cnt;
  int hash;
  struct token* next;
} Token;
Token* tokens;
bool hash_record[MOD] = { false };  // opt
int hash(char* str) {
  int ret = 0;
  while (*str != '\0')
    ret = (ret << 7 + ret >> 5 + *str++) % MOD;
  return ret;
}
Token* tk_find(char* t) {
  Token* p = tokens->next;
  int h = hash(t);
  while (p) {
    if (h==p->hash && !strcmp(t, p->val)) return p;
    p = p->next;
  }
  return NULL;  
}
#define isalphanum(c) ('a'<=c&&c<='z' || 'A'<=c&&c<='Z' || '0'<=c&&c<='9')
#define tolower(c) (('A'<=c&&c<='Z') ? (c-'A'+'a') : c)

char str[NSTR], DELIM = ' ';
int main() {
  tokens = malloc(sizeof(Token));
  tokens->val = tokens->next = NULL;  // dummy node

  char *p = str, c;
  while (c = getchar()) {
    if (c == '\n') break;
    if (isalphanum(c)) *p++ = tolower(c);
    else if (p!=str && *(p-1)!=DELIM) *p++ = DELIM; // the delimiter
  }
  *p = '\0';  // fix str

  int maxcnt = 0;
  Token *maxtok = tokens->next, *q = tokens->next;
  char* t = strtok(str, &DELIM);
  while (t) {
    int h = hash(t);
    Token* p = hash_record[h] ? tk_find(t) : NULL;
    if (p) p->cnt++;
    else {  // new token
      p = malloc(sizeof(Token));
      p->val = malloc((strlen(t) + 1) * sizeof(char));
      strcpy(p->val, t);
      p->cnt = 1;
      p->hash = h; hash_record[h] = true;
      p->next = tokens->next; // insert head
      tokens->next = p;
    }
    if (p->cnt > maxcnt  || p->cnt == maxcnt 
        && h == p->hash && strcmp(p->val, maxtok->val) < 0) {
      maxcnt = p->cnt;
      maxtok = p;
    }
    t = strtok(NULL, &DELIM);
  }

  printf("%s %d", maxtok->val, maxcnt);
}
