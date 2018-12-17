#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int cmp(const void *a, const void *b) {
  return *(int*)a - *(int*)b;
}

int main()
{
  int *num=NULL;
  int n, i, ans=0x7fffffff;

  scanf("%d", &n);
  num=realloc(num, n*sizeof(int));
  for(i=0;i<n;i++) scanf("%d", &num[i]);
  qsort(num, n, sizeof(int), cmp);

  int diff;
  for(i=1;i<n;i++) {
    diff=(num[i]-num[i-1]);
    if(diff<ans) {
      ans=diff;
      if(ans==0) break;
    }
  }
  printf("%d\n", ans);
  return 0;
}
