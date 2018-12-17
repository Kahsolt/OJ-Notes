#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define N 101
#define NSTR 11
/* List Grades (25) */

typedef struct record {
  char name[NSTR];
  char ID[NSTR];
} Record;
Record* records[N];

int main() {
  int n; scanf("%d", &n); getchar();
  while (n--) {
    char name[NSTR], ID[NSTR]; int grade;
    scanf("%s %s %d", name, ID, &grade); getchar();
    Record* r = malloc(sizeof(Record));
    strcpy(r->name, name);
    strcpy(r->ID, ID);
    records[grade] = r;
  }

  int x, y; scanf("%d%d", &x, &y);
  bool found = false;
  for (int i=y; i>=x; i--)
    if(records[i]) {
      found = true;
      printf("%s %s\n", records[i]->name, records[i]->ID);
    }
  if (!found) puts("NONE");
}