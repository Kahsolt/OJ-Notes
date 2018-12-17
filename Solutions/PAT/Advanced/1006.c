#include <stdio.h>
#include <string.h>
#define NNAME 16
#define NTIME 9
/* Sign In and Sign Out (25) */

int main() {
  char first[NNAME], last[NNAME], first_time[NTIME], last_time[NTIME],
       name[NNAME], timein[NTIME], timeout[NTIME];
  int n;

  scanf("%d", &n); getchar();
  /* first case */
  scanf("%s %s %s", name, timein, timeout); getchar();
  strcpy(first, name); strcpy(last, name);
  strcpy(first_time, timein); strcpy(last_time, timeout);
  for (int i=1; i<n; i++) { /* rest cases */
    scanf("%s %s %s", name, timein, timeout); getchar();
    if (strcmp(timein, first_time) < 0) {
      strcpy(first_time, timein);
      strcpy(first, name);
    }
    if (strcmp(timeout, last_time) > 0) {
      strcpy(last_time, timeout);
      strcpy(last, name);
    }
  }
  printf("%s %s\n", first, last);
}