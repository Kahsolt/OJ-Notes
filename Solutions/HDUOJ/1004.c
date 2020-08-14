// Let the Balloon Rise

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#define MAXN 1000
#define MAXSTR 16

struct balloon {
  char color[MAXSTR];
  int count;
} balloons[MAXN];

int main() {
  int n; while(~scanf("%d", &n)) {
    if (!n) break; getchar();
    
    int balloon_cnt = 0;
    while (n--) {
      char color[MAXSTR]; scanf("%s", color); getchar();
      bool found = false;
      for (int i=0; i<balloon_cnt; i++)
        if (!strcmp(color, balloons[i].color)) {
          balloons[i].count++;
          found = true; break;
        }
      if (!found) {
        strcpy(balloons[balloon_cnt].color, color);
        balloons[balloon_cnt++].count = 1;
      }
    }

    int maxcnt = 0, maxidx = -1;
    for (int i=0; i<balloon_cnt; i++)
      if (balloons[i].count > maxcnt)
        maxcnt = balloons[maxidx = i].count;

    printf("%s\n", balloons[maxidx].color);
  }
}