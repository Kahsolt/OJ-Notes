#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define N   100000
#define MOD 100007

typedef struct grimoire {
  char spell[21];   struct grimoire* spell_next;
  char effect[81];  struct grimoire* effect_next;
} Grimoire;
Grimoire grimoires[N], *grimoires_cur = grimoires;
Grimoire *spell_has[MOD] = { NULL }, *effect_has[MOD] = { NULL };  // hash link

int hash(char* str) {
  int h = 0;
  while (*str != '\0')
    h = ((h << 7) + (h >> 5) + *str++) % MOD;
  return h;
}

int main() {
  while (true) {
    if (getchar() != '[') { scanf("%*[^\n]s"); getchar(); break; }
    scanf("%[^]]s", grimoires_cur->spell); getchar(); getchar();
    int h = hash(grimoires_cur->spell);
    grimoires_cur->spell_next = spell_has[h];
    spell_has[h] = grimoires_cur;
    gets(grimoires_cur->effect);
    h = hash(grimoires_cur->effect);
    grimoires_cur->effect_next = effect_has[h];
    effect_has[h] = grimoires_cur++;  // remeber increase
  }
  int n; scanf("%d", &n); getchar(); while (n--) {
    char query[81], c = getchar();
    if (c == '[') {
      scanf("%[^]]s", query); getchar(); getchar();
      Grimoire* p = spell_has[hash(query)];
      while (p && strcmp(query, p->spell)) p = p->spell_next;
      puts(p ? p->effect : "what?");
    } else {
      ungetc(c, stdin); gets(query);
      Grimoire* p = effect_has[hash(query)];
      while (p && strcmp(query, p->effect)) p = p->effect_next;
      puts(p ? p->spell : "what?");
    }
  }
}