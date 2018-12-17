#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>

// 2018-08-27

void filter0(int N) { /* O(nloglogn) */
  bool* flag = malloc(N * sizeof(bool) + 1);
  for (int i=2; i<=N; i++) flag[i] = true;

  clock_t t = clock();
  for (int i=2; i<=(int)sqrt(N + 0.5); i++)
    if (flag[i])
      for (int j=i*i; j<=N; j+=i)
        flag[j] = false;
  printf("%s: %d\n", __FUNCTION__, clock() - t);

  if (N <= 100) {
    for (int i=2; i<=N; i++)
      if (flag[i]) printf("%d ", i);
    putchar(10);
  }
  free(flag);
}

void filter(int N) { /* O(n), but actual slower than filter0 */
  bool* flag = malloc(N * sizeof(bool) + 1);
  for (int i=2; i<=N; i++) flag[i] = true;

  clock_t t = clock();
  /* non-primes are N=p^k*q, where q>p */
  for(int p=2; p<=(int)sqrt(N + 0.5); p++)
    if(flag[p])
      for(int q=p; p*q<=N; q++)
        for(int k=p*q; k<=N; k*=p)
          flag[k] = false;
  printf("%s: %d\n", __FUNCTION__, clock() - t);
  
  if (N <= 100) {
    for (int i=2; i<=N; i++)
      if (flag[i]) printf("%d ", i);
    putchar(10);
  }
  free(flag);
}

bool isprime(int x) {
  if (x <= 1) return false;
  if (x==2 || x==3) return true;
  for (int i=2; i<=(int)sqrt(x + 0.5); i++)
    if (!(x%i))
      return false;
  return true;
}

int main() {
  printf("%d ", isprime(2));
  printf("%d ", isprime(3));
  printf("%d ", isprime(25));
  putchar(10);
  filter0(1000000);
  filter(1000000);
}