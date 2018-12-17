#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define N 100+1

// 2018/08/27
// 有穷自动机 (matrix ver)
//

typedef char DATATYPE;
typedef int STATE;
// This automaton accepts string with odd '1's
int F[2][2] = { // state indexed from 0 to (n-1)
  0, 1,
  1, 0,
};
bool terminal[2] = { false, true };
static inline bool fa_run(STATE cur, DATATYPE data[], size_t len) {
  for (int i=0; i<len; i++)
    cur = F[cur][data[i] & 0x0F];
  return terminal[cur];
}

int main() {
  STATE S = 0;
  int t = 5;
  DATATYPE data[][N] = {
    "001",
    "1010100",
    "1001",
    "1110110",
    "10101010",
  };
  for (int i=0; i<t; i++)
    puts(fa_run(S, data[i], strlen(data[i]))
        ? "Yes" : "No");
}