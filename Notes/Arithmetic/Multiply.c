#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 8bit number multipy */

int Mul1(int x, int y)
{
#define BITS 8
  int i;
  y<<=BITS;
  for(i=0;i<BITS;i++)
  {
    if(x & 0x1u) x+=y;
    x>>=1;
  }
  return x;
}

int Mul2(int x, int y)
{
  int ans=0;
  while(x)
  {
    ans<<=1;
    if(x & 0x1u) ans+=y;
    x>>=1;
  }
  return ans;
}


int main()
{
  int x=0xAD;	/* 10101101 */
  int y=0x39;	/* 00111001 */

  printf("Method #1: %d\n", Mul1(x, y));
  printf("Method #2: %d\n", Mul2(x, y));

  return 0;
}
