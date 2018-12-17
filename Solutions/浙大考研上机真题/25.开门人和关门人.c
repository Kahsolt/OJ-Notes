#include <stdio.h>
#include <string.h>
#define forr(i, a, b) for(int i=a;i<b;i++)
#define read(x) int x; scanf("%d",&x)
#define NSTR 16
#define NTIME 9

int main() {
  char first_id[NSTR], last_id[NSTR], 
       first_time[NTIME], last_time[NTIME];
  read(n); getchar();
  
  scanf("%s%s%s", first_id, first_time, last_time);
  strcpy(last_id, first_id);
  forr(i, 1, n) {
    char id[NSTR], rtime[NTIME], ltime[NTIME];  // register time/ leave time
    scanf("%s%s%s", id, rtime, ltime); getchar();
    if (strcmp(rtime, first_time) < 0) {
      strcpy(first_time, rtime);
      strcpy(first_id, id);
    }
    if (strcmp(ltime, last_time) > 0) {
      strcpy(last_time, ltime);
      strcpy(last_id, id);
    }
  }
  printf("%s %s", first_id, last_id);
}