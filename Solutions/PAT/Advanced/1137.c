#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define forr(i, a, b) for(int i=a;i<b;i++)
#define forp(i, a, b) for(int i=a;i<=b;i++)
#define times(n) int _##n=n;while(_##n--)
#define mset(d, v) memset(d,v,sizeof(d))
#define min(a, b) (((a)<=(b))?(a):(b))
#define swap(a, b) (a)^=(b)^=(a)^=(b)
#define input(x) scanf("%d",&x)
#define read(x) int x;input(x)
#define prtl() putchar('\n')
#define prti(x) printf("%d", x)
#define prta(x, a, b) forr(i,a,b){if(i!=a)putchar(' ');prti(x[i]);}
#define MOD 100007
#define N 10000
#define NSTR 21
/* Final Grading (25) */

typedef struct student {
  char ID[NSTR];
  int hash;
  int pgrade, midgrade, fingrade, grade;
  struct student* next;
} Student;
Student* students;
#define prt_student(s) \
    printf("%s %d %d %d %d\n", \
        s->ID, s->pgrade, s->midgrade, s->fingrade, s->grade);

bool hash_has[MOD] = { false };  // opt
int hash(char* str) {
  int ret = 0;
  while (*str != '\0')
    ret = (ret << 7 + ret >> 5 + *str++) % MOD;
  return ret;
}

Student* ll_find(char* ID, int h) {
  Student* p = students->next;
  while (p) {
    if (h == p->hash && !strcmp(ID, p->ID)) return p;
    p = p->next;
  }
  return NULL;
}
int cmp(Student* sa, Student* sb) { // '>':'<'
  int gcmp = sa->grade - sb->grade; 
  return gcmp ? gcmp : strcmp(sa->ID, sb->ID);
}
void ll_sort() {
  Student *p = students->next, *fp = students;
  while (p->next) { // still swappable
    Student *maxidx = p, *fmaxidx = NULL;  // record max node
    Student *fq = p, *q = p->next; // father of q
    while (q) {
      if (cmp(q, maxidx) > 0) { maxidx = q; fmaxidx = fq; }
      fq = q; q = q->next;  // shift
    }
    if (maxidx != p) {    // found replacement
      fmaxidx->next = maxidx->next; // detach maxidx
      maxidx->next = fp->next;  // insert maxidx after p
      fp->next = maxidx;
    }
    fp = p; p = p->next;
  }
}
int main() {
  students = malloc(sizeof(Student));
  students->next = NULL;  // dummy head node

  read(p); read(m); read(n); getchar();
  char ID[NSTR]; int grade;
  times(p) {
    scanf("%s%d", ID, &grade); getchar();
    if (grade < 200) continue;  // ignore uncertified
    int h = hash(ID);
    Student* n = malloc(sizeof(Student));
    strcpy(n->ID, ID);
    n->pgrade = grade;
    n->midgrade = n->fingrade = n->grade = -1;
    n->hash = h; hash_has[h] = true;
    n->next = students->next; // insert head
    students->next = n;
  }
  times(m) {
    scanf("%s%d", ID, &grade); getchar();
    int h = hash(ID);
    Student* p = hash_has[h] ? ll_find(ID, h) : NULL;
    if (p) p->midgrade = grade;
  }
  times(n) {
    scanf("%s%d", ID, &grade); getchar();
    int h = hash(ID);
    Student* p = hash_has[h] ? ll_find(ID, h) : NULL;
    if (p) {
      p->fingrade = grade;
      p->grade = p->midgrade > p->fingrade
          ? round((p->midgrade * 2 + p->fingrade * 3) / 5.0)
          : p->fingrade;
      if (p->grade < 60) {  // ignore uncertified
        Student *q = students->next, *fp;
        while (q != p) { fp = q; q = q->next; }
        fp->next = p->next;
        free(p);
      }
    }
  }

  ll_sort();
  Student* q = students->next;
  while (q) { prt_student(q); q = q->next; }
}