#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#define N 1000000
#define NCHAR 26
#define MOD 100003  // 4e+7 5e+3  不能选太大，@可能溢出

// 2017-9-13
// 想过类似方法，但使用的逐字节异或作为hash函数
// 2018/08/07
// 判断字符串匹配 s.contains(t)，另参考KMP算法
//

int match_brute_force(char* s, char* t) {
  int len = strlen(t);
  for (int r=0; r<=strlen(s)-len+1; r++) {  // at most strlen(s)-len+1 round trials
    int i = r, j = 0;
    while (j < len && s[i++] == t[j++])
      if (j == len) return r;
  }
  return -1;
}

int hash[N];    // hash[i]: hash value of prefix string s[0..i-1]
int modpow[N];  // modpow[i]: (26^i) mod MOD, helper for calc
void init_hash(char *s) {
  modpow[0] = 1;  // 26^0 mod MOD == 1
  hash[0] = 0;    // hash value of null string is 0
  for (int i=1; i<=strlen(s); i++) {  // 注意这里取等，算全串的hash
    modpow[i] = (modpow[i-1] * NCHAR) % MOD;
    hash[i] = (hash[i-1] * NCHAR + s[i-1] - 'a') % MOD; // 'a'~'z' offset to 0~25
  }
}
int get_hash(int i, int j) { // hash value of s[i..j-1]
  int tmp = (hash[j] - hash[i] * modpow[j-i]) % MOD;  // 可能溢出
  return tmp >= 0 ? tmp : tmp + MOD;
}
bool memequ(char s1[], char s2[], int n) {  // or memcmp()
  while (n--) if (s1[n] != s2[n]) return false;
  return true;
}
int match_hash(char* s, char* t) {
  init_hash(s); // hash of s[] prefix strings
  int hash = 0, len = strlen(t);
  for (int i=0; i<len; i++)  // hash of t
    hash = (hash * NCHAR + t[i] - 'a') % MOD; 

  for (int i=0; i<strlen(s)-len+1; i++)
    if (get_hash(i, i+len)==hash && memequ(&s[i], t, len))
      return i;
  return -1;
}

int main() {
  srand(time(NULL));
  char s[N], t[N];

  int r = rand() % 10 + 1;
  while (r--) {
    int lens = rand() % (N-1) + 1;
    for (int i=0; i<lens; i++)
      s[i] = rand() % NCHAR + 'a';
    s[lens] = '\0';
    int lent = __max(__min(lens >> 10, 3), 2);
    for (int i=0; i<lent; i++)
      t[i] = rand() % NCHAR + 'a';
    t[lent] = '\0';

    clock_t e;
    int m1, m2;
    e = clock();
    m1 = match_brute_force(s, t);
    printf("[match_brute_force]: %d\n", clock() - e);
    e = clock();
    m2 = match_hash(s, t);
    printf("[match_hash]: %d\n", clock() - e);
    if (m1 == m2) printf("Match at %d\n", m1); // aka. m2
    else {
      printf("Medthods Mismatch: %d != %d\n", m1, m2);
      printf("lens=%d lent=%d\n", lens, lent);
      for (int i=0; i<lent; i++)
        printf("%c", t[i]); putchar(10);
      for (int i=m1; i<m1+lent; i++)
        printf("%c", s[i]); putchar(10);
      for (int i=m2; i<m2+lent; i++)
        printf("%c", s[i]); putchar(10);
    }
    puts("=====================");
  }
}