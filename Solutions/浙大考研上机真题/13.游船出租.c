#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>
#define N 101

/* 题意很奇怪，放弃 */

int boats[N]; // the timestamp of start
int main() {
  memset(boats, 0xFF, sizeof(boats));
  unsigned int cnt = 0, sum = 0;
  char record[10]; while (gets(record)) {
    int id; sscanf(record, "%d", &id);
    if (id == -1) break;
    else if (!id) { // one day off, report and reset
      double avg = !sum ? 0 : (double)sum / cnt;
      printf("%d %d\n", cnt, (int)ceil(avg));
      cnt = sum = 0; memset(boats, 0xFF, sizeof(boats));
    } else {
      char act; int hr, min; sscanf(record, "%*d %c %d:%d", &act, &hr, &min);
      if (boats[id]==-1 && act == 'S')
        boats[id] = hr * 60 + min;
      else if (boats[id] != -1) {
        sum += ( hr * 60 + min - boats[id]);
        cnt++;
        boats[id] = -1;
      }
    }
  }
}
