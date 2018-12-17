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
#define read(x) int x;scanf("%d",&x)
#define prtl() putchar('\n')
#define prti(x) printf("%d", x)
#define prta(x, a, b) forr(i,a,b){if(i!=a)putchar(' ');prti(x[i]);}
#define N 100000
#define K 2500
/* Course List for Student (25) */

/* a name is a 3-digit number with base 26 
   ranged from AAA(0) to ZZZ(17575),
   with a hash barrel of 10 */
/* NOTE: define as macro, since functions would TLE */
#define name_hash(str) \
    ((*str - 'A') * 26 * 26 \
    + (*(str + 1) - 'A') * 26 \
    + (*(str + 2) - 'A'))
#define name_barrel(str) (*(str + 3) & 0x0F)

// #define METHOD1
#define METHOD2  /* this will TLE a little */

#ifdef METHOD1    /* more time, less space */
typedef struct course {
  int id;
  struct course* next;
} Course;
typedef struct course_list {
  int count;
  Course* courses;
} CourseList;
CourseList course_lists[10][17576] = { 0 };

int main() {
  read(n); read(k); times(k) {
    read(id); read(m); times(m) {
      char name[5]; scanf("%s", name);
      Course* c = malloc(sizeof(Course));
      c->id = id; c->next = NULL;
      CourseList* cs = &course_lists[name_barrel(name)][name_hash(name)];
      cs->count++;
      Course* p = cs->courses;
      if (!p) cs->courses = c;  // fill head
      else if (id <= p->id) { // insert head
        c->next = p;
        cs->courses = c;
      } else {
        while (p->next && p->next->id < id) p = p->next;
        c->next = p->next;
        p->next = c;
      }
    }
  }
  times(n) {
    char name[5]; scanf("%s", name);
    CourseList* cs = &course_lists[name_barrel(name)][name_hash(name)];
    printf("%s %d", name, cs->count);
    Course* p = cs->courses;
    if (p) while (p) {
      printf(" %d", p->id);
      p = p->next;
    }
    prtl();
  }
}
#endif

#ifdef METHOD2    /* more time, less space */
bool courses[10][17576][K+1] = { false };
short courses_cnt[10][17576] = { 0 };

int main() {
  read(n); read(k); times(k) {
    read(id); read(m); times(m) {
      char name[5]; scanf("%s", name);
      int b = name_barrel(name), h = name_hash(name);
      courses[b][h][id] = true;
      courses_cnt[b][h]++;
    }
  }
  times(n) {
    char name[5]; scanf("%s", name);
    int b = name_barrel(name), h = name_hash(name);
    int cnt = courses_cnt[b][h];
    printf("%s %d", name, cnt);
    for (int i=1; cnt && i<=k; i++)
      if (courses[b][h][i]) {
        printf(" %d", i);
        cnt--;
      }
    prtl();
  }
}
#endif