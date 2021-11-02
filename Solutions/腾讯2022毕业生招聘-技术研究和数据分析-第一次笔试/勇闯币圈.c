#include <stdio.h>

/*
2
2
0.4 0.2 0.4
0.2 0.1 0.7
0.3 0.5 0.2
0.5 0.4 0.1
10
0.4 0.2 0.4
0.2 0.1 0.7
0.3 0.5 0.2
0.5 0.4 0.1
*/

float pi[3] = { 0 };
float P[3][3] = { 0 };

void mul() {
  float tmp[3];
  for (int i=0; i<3; i++) tmp[i] = 0.0;
  
  for (int i=0; i<3; i++)
    for (int j=0; j<3; j++)
      tmp[i] += pi[j] * P[i][j];

  for (int i=0; i<3; i++) pi[i] = tmp[i];
}

int main() {
  int T; scanf("%d", &T);
  while (T--) {
    int t; scanf("%d", &t);
    for (int i=0; i<3; i++)
      scanf("%f", &pi[i]);
    for (int i=0; i<3; i++)
      for (int j=0; j<3; j++)
        scanf("%f", &P[i][j]);

    while (t--) mul();

    puts(pi[2] > 0.5 ? "1" : "0");
  }
}