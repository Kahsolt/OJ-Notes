#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>
#define eps 1e-8

typedef struct term {
  double coeff;
  int exp;
  struct term *next;
} Term;

void poly_add(Term* t1, Term* t2) {
  while (t2) {
    Term* p = t1;
    while (p && t2->exp<p->exp) p = p->next;
    if (p && p->exp == t2->exp) {
      p->coeff += t2->coeff;
      if (p->coeff < eps) {
        // Del node
      }
    } else {
      // Ins node
    }
    t2 = t2->next;
  }
}

void poly_print(Term* t) {
  while (t) {
    printf("+%.2X^%d", t->coeff, t->exp);
    t = t->next;
  }
}

int main() {

  return 0;
}