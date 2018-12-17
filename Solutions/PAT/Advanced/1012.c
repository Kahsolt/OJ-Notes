#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define forr(i, a, b) for(int i=a;i<b;i++)
#define mset(d, v) memset(d,v,sizeof(d))
#define min(a, b) (((a)<=(b))?(a):(b))
#define swap(a, b) (a)^=(b)^=(a)^=(b)
#define read(x) int x;scanf("%d",&x)
#define prtl() putchar('\n')
#define prti(x) printf("%d", x)
#define prta(x, a, b) forr(i,a,b){if(i!=a)putchar(' ');prti(x[i]);}
#define N 2000
#define NID 1000000
/* The Best Rank (25) */

typedef struct student {
  int ID;
  int C, M, E, A;
  int bestrank;
  char subject;
} Student;
Student students[N], *student_cur = students;

int cmpID(const void* a, const void* b) { return ((Student*)a)->ID - ((Student*)b)->ID; }
int cmpA(const void* a, const void* b) { return ((Student*)b)->A - ((Student*)a)->A; }
int cmpC(const void* a, const void* b) { return ((Student*)b)->C - ((Student*)a)->C; }
int cmpM(const void* a, const void* b) { return ((Student*)b)->M - ((Student*)a)->M; }
int cmpE(const void* a, const void* b) { return ((Student*)b)->E - ((Student*)a)->E; }
void adjust_rank(char subject) {
  Student* p = students;
  int rank = 1;
  while (p != student_cur) {
    if (rank < p->bestrank) {
      p->bestrank = rank;
      p->subject = subject;
    }
    rank++; p++;
  }
}
int main() {
  read(n); read(m);
  forr(i, 0, n) {
    int ID, C, M, E, A;
    scanf("%d%d%d%d", &ID, &C, &M, &E);
    student_cur->bestrank = n + 1;
    student_cur->ID = ID;
    student_cur->C = C;
    student_cur->M = M;
    student_cur->E = E;
    student_cur->A = (C + M + E) / 3;
    student_cur++;
  }
  qsort(students, n, sizeof(Student), cmpA); adjust_rank('A');
  qsort(students, n, sizeof(Student), cmpC); adjust_rank('C');
  qsort(students, n, sizeof(Student), cmpM); adjust_rank('M');
  qsort(students, n, sizeof(Student), cmpE); adjust_rank('E');
  qsort(students, n, sizeof(Student), cmpID);
  while (m--) {
    read(ID);
    Student* s = bsearch(&ID, students, n, sizeof(Student), cmpID);
    if (!s) puts("N/A");
    else printf("%d %c\n", s->bestrank, s->subject);
  }
}
