#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXARRAY 101
#define MAXSTR 11
#define MINSTR 2
/* Boys vs Girls (25) */

typedef struct student {
  char *name;
  char gender;
  char *ID;
} Student;

Student* students[MAXARRAY];
int main() {
  memset(students, 0x00, MAXARRAY * sizeof(Student*));
  
  int N; scanf("%d", &N); getchar();
  while (N--) {
    char* name = malloc(MAXSTR * sizeof(char));
    char* gender = malloc(MINSTR * sizeof(char));
    char* ID = malloc(MAXSTR * sizeof(char));
    int grade;
    scanf("%s %s %s %d", name, gender, ID, &grade); getchar();
      
    Student* s = malloc(sizeof(Student));
    s->name = malloc((strlen(name) + 1) * sizeof(char));
    strcpy(s->name, name);
    s->gender = gender[0];
    s->ID = malloc((strlen(ID) + 1) * sizeof(char));
    strcpy(s->ID, ID);
    students[grade]=s;
  }

  char p = 100, q = 0;
  while (p>=0 && (students[p]==NULL || students[p]->gender!='F')) p--;
  while (q<=100 && (students[q]==NULL || students[q]->gender!='M')) q++;
  
  if (p == -1) printf("Absent\n");
  else printf("%s %s\n", students[p]->name, students[p]->ID);
  if (q == 101) printf("Absent\n");
  else printf("%s %s\n", students[q]->name, students[q]->ID);
  if (p==-1 || q==101) printf("NA\n");
  else printf("%d\n", p - q);
}