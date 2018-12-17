#include <stdio.h>
#include <math.h>

int main() {
  double P, T, G1, G2, G3, GJ;
  while (~scanf("%lf%lf%lf%lf%lf%lf", &P, &T, &G1, &G2, &G3, &GJ)) {
    double ans;
    double t = abs(G1 - G2);
    if (t <= T) ans = (G1 + G2) / 2;
    else {
      double t1 = abs(G3 - G1);
      double t2 = abs(G3 - G2);
      if (t1<=T && t2<=T){
        ans = G1>G2 ? G1 : G2;
        if (G3 > ans) ans = G3;
      } else if (t1<=T || t2<=T) {
        double closest = abs(t1-T)<abs(t2-T) ?t1 : t2;
        ans = (G3 + closest) / 2;
      } else ans = GJ;
    }
    printf("%.1f\n", ans);
  }
}