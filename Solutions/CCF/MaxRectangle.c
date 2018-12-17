#include <stdio.h>
#include <stdlib.h>
#define MAX_N 1000
#define MAX_HEIGHT 10000
#define D

int n, *height;
int ans = 0;

void findMax(int left, int right)
{
#ifdef D
  printf("try(%d, %d)\n", left, right);
#endif

  int i, area;
  int minHeight = height[left], idx = left;
  for(i = left + 1; i <= right; i++)
    if(height[i] < minHeight) minHeight = height[idx=i];

  area = (right - left + 1) * minHeight;
  if(area > ans) ans = area;

  if(left < idx) findMax(left, idx - 1);
  if(idx < right) findMax(idx + 1, right);
}

int main()
{
  int i;

  scanf("%d", &n);
  height = (int *)malloc(n * sizeof(int));
  for(i=0; i<n; scanf("%d", &height[i++]));

  findMax(0, n - 1);
  printf("%d", ans);

  return 0;
}
