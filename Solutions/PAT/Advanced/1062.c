#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSTR 9
/* Talent and Virtue (25) */

typedef struct person {
  char id[MAXSTR];
  unsigned int v : 7;
  unsigned int t : 7;
  unsigned int sum : 8;
  unsigned int type : 2;  /* 0=sage 1=nobleman 2=foolman 3=others */
} Person;

int less(Person *p1, Person *p2) {
  if (p1->type < p2->type) return 1;
  else if (p1->type > p2->type) return 0;
  if (p1->sum > p2->sum) return 1;
  else if (p1->sum < p2->sum) return 0;
  if (p1->v > p2->v) return 1;
  else if (p1->v < p2->v) return 0;
  if (strcmp(p1->id, p2->id) < 0) return 1;
  return 0;
}
void Qsort(Person* persons[], int left, int right) {
  int x = left, y = right;
  Person* pit = persons[x];
  while(x < y) {
    while(x<y && less(pit, persons[y])) y--;
    persons[x] = persons[y];
    while(x<y && less(persons[x], pit)) x++;
    persons[y] = persons[x];
  }
  persons[x] = pit;
  if(left < y - 1) Qsort(persons, left, y-1);
  if(x + 1 < right) Qsort(persons, x+1, right);
}

void print(Person* persons[], int M) {
  printf("=======\n");
  for (int i=0; i<M; i++)
    printf("%s %d %d %d %d\n",
            persons[i]->id, persons[i]->v, persons[i]->t,
            persons[i]->sum, persons[i]->type);
}

int main() {
  int N, L, H, M = -1; scanf("%d%d%d", &N, &L, &H);
  Person** persons = malloc(N*sizeof(Person*));
  while (N--) {
    char id[MAXSTR]; int v, t;
    scanf("%s%d%d", id, &v, &t); getchar();
    if (v<L || t<L) continue;

    Person* p = malloc(sizeof(Person));
    strcpy(p->id, id);
    p->v = v; p->t = t; p->sum = v + t;
    if(v>=H && t>=H) p->type = 0; /* sage */
    else if(t<H && v>=H) p->type = 1; /* nobleman */
    else if(t<H && v<H && v>=t) p->type = 2;  /* fool men */
    else p->type = 3; /* others */
    persons[++M] = p;
  }
  /* print(persons, M); */
  Qsort(persons, 0, M);
  /* print(persons, M); */

  printf("%d\n", M + 1);
  for (int i=0; i<=M; i++)
    printf("%s %d %d\n",
      persons[i]->id, persons[i]->v, persons[i]->t);
}