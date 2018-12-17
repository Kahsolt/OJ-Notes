#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int main()
{
  int n, k, i, cnt;
  int *next=NULL;

  scanf("%d%d", &n, &k);
  next=realloc(next, (n+1)*sizeof(int));
  for(i=1;i<n;i++) next[i]=i+1; next[n]=1;

  i=n; cnt=1;
  while(n>1) {
    if(cnt%k==0 || cnt%10==k) {
      next[i]=next[next[i]];
      n--;
    } else i=next[i];
    cnt++;
  }

  printf("%d\n", i);

  return 0;
}
