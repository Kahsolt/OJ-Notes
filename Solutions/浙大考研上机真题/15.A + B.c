#include <stdio.h>
#include <stdbool.h>
#define N 10

// truncated digital string
char digstr[N][3] = {
  "ze", "on", "tw", "th", "fo",
  "fi", "si", "se", "ei", "ni"
};
// mapping: string hash => numeric digit
char dighash[26*26] = { 0 };
// taken as number based in 26
#define hash(str) \
  (*str - 'a') * 26 + (*(str + 1) - 'a')

int main() {
  for (int i=0; i<N; i++)   // init hash mapping
    dighash[hash(digstr[i])] = i;
  
  char buf[6];
//  while (true) {
    int a = 0; while (true) {
      scanf("%s", buf); getchar();
      if (buf[0] == '+') break;
      a = a * N + dighash[hash(buf)];
    }
    int b = 0; while (true) {
      scanf("%s", buf); getchar();
      if (buf[0] == '=') break;
      b = b * N + dighash[hash(buf)];
    }
//    if (!a && !b) break;
    printf("%d\n", a + b);
//  }
}