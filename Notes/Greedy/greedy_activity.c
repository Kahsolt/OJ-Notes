#include <stdio.h>
#include <stdlib.h>
#define N 10001

typedef struct {
  int start, finish;
} Activity;
Activity activities[N];
int cmp(const void* a, const void* b) {
  Activity* aa = (Activity*)a;
  Activity* ab = (Activity*)b;
  int cmpfin = ab->finish - aa->finish;
  return cmpfin ? cmpfin : aa->start - ab->start; 
}

int trace[N] = { 0 }, trace_cnt = 0;
void greedy_activity(int n) {
	trace[trace_cnt++] = 1;   // 选入第一个活动
	int p = 1;	//指向答案子集中的最后一个活动 
	for (int i=2; i<=n; i++)
	  if (activities[i].start >= activities[p].finish) {	//取等，端点可重叠
	    trace[trace_cnt++] = i;
		  p = i;
	  }
}

void print() {
	printf("The Maxset conclude %d activities: \n", trace_cnt);
	for(int i=0; i<trace_cnt; i++)
    printf("%d ", trace[i]);
  putchar(10);
}

int main() {
  int n; scanf("%d", &n);
  for (int i=1; i<=n; i++)
		scanf("%d%d", &activities[i].start, &activities[i].finish);
  qsort(activities, n, sizeof(Activity), cmp);
  greedy_activity(n);
  print();
}

/* Sample Input: (Ans=4)
11
1 4
0 6
5 7
5 9
8 11
2 13
12 14
3 5
5 9
8 11
2 13
*/

