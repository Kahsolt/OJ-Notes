#include <stdio.h>
/* A+B in Hogwarts (20) */

int main() {
  unsigned int Ga, Sa, Ka, Gb, Sb, Kb;
  scanf("%u.%u.%u %u.%u.%u", &Ga, &Sa, &Ka, &Gb, &Sb, &Kb);
  Ga += Gb; Sa += Sb; Ka += Kb;
  Sa += Ka / 29; Ka %= 29;
  Ga += Sa / 17; Sa %= 17;
  printf("%u.%u.%u\n", Ga, Sa, Ka);
}