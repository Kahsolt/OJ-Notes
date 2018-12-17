#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define read(x) int x; scanf("%d", &x);
#define N 1000
/* Raffle for Weibo Followers (20) */

char* winlist[N];
int wincnt = 0;
int main() {
  read(m); read(n); read(s); getchar();
  int cnt = 1;  /* first winner magic offset number */
  while (m--) {
    char name[21]; gets(name);
    if (--s > 0) continue;
    bool rep = false;
    for (int i=0; !rep && i<wincnt; i++)
      if (!strcmp(name, winlist[i]))
        rep = true;
    if (!rep && !--cnt) {
      puts(name);
      winlist[wincnt] = malloc((strlen(name) + 1) * sizeof(char));
      strcpy(winlist[wincnt], name);
      wincnt++;
      cnt = n;  /* recount */
    }
  }
  if (!wincnt) puts("Keep going...");
}
