#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define forr(i, a, b) for(int i=a;i<b;i++)
#define times(n) int _##n=n;while(_##n--)
#define mset(d, v) memset(d,v,sizeof(d))
#define input(x) scanf("%d",&x)
#define read(x) int x;input(x)
#define prti(x) printf("%d\n", x)
#define N 1000
#define M 10

typedef struct student {
  char ID[21];
  int grade;
} Student;
Student students[N], *students_cur;
int cmp(const void* a, const void* b) {
  Student *sa = (Student*)a, *sb = (Student*)b;
  int cmpgrd = sb->grade - sa->grade;
  return cmpgrd ? cmpgrd : strcmp(sa->ID, sb->ID);
}
int score[M]; // score for each problem

int main() {
  int n; while (~input(n)) {
    if (!n) break; read(m); read(g);
    forr(i, 0, m) input(score[i]); getchar();
    students_cur = students;
    times (n) {
      scanf("%s", students_cur->ID);
      int sum = 0;
      read(k); times(k) {
        read(pid); sum += score[pid-1]; // offset
      } getchar();
      if (sum >= g) { // filter
        students_cur->grade = sum;
        students_cur++;
      }
    }
    int cnt = students_cur - students;
    qsort(students, cnt, sizeof(Student), cmp);
    
    prti(cnt);
    forr(i, 0, cnt)
      printf("%s %d\n", students[i].ID, students[i].grade);
  }
}