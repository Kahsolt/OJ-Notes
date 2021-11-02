#include <stdio.h>
#include <string.h>

#define MOD 1000000007

char cnt[26] = { 0 };

int A(int n) {
  long long r = 1;
  for (int i=1; i<=n; i++)
    r = r * i % MOD;
  return r;
}

// valid words looks like "CVCV..CV"  or "CVCV..C"
int solution(char *S) {
  if (!S) return 0;
  int len = strlen(S);
  if (!len) return 0;

  int cntV = 0;
  char *p = S;
  while (*p) {
    cnt[*p - 'A']++;
    switch (*p) {
      case 'A': case 'E': case 'I': case 'O': case 'U':
        cntV++; break;
    }
    p++;
  }
  int cntC = len - cntV;
  if (!(cntC == cntV || cntC == cntV + 1)) return 0;

  long long r = A(cntC) * A(cntV) % MOD, s = 1;
  for (int i=0; i<26; i++)
    if (cnt[i])
      s = s * A(cnt[i]) % MOD;

  return r / s;
}

void go(char* S) {
  printf("%s => %d\n", S, solution(S));
  memset(cnt, 0x00, sizeof(cnt));
}

int main() {
  go("");
  go("A");
  go("C");
  go("BAR");
  go("AABB");
  go("AABCY");
  go("AAAB");
  go("AABBAABBAABBAABBAABBAABB");
  go("AABBAABBAABBAABBAABBAABBC");
  go("AABBAABBAABBAABBAABBAABBAABBAABBAABBAABBAABBAABBAABBAABBAABB");
  go("AABBAABBAABBAABBAABBAABBAABBAABBAABBAABBAABBAABBAABBAABBAABBC");
}
