#include <iostream>
#include <iomanip>
#include <map>
using namespace std;
#define eps 1e-8
// A+B for Polynomials (25)

int main() {
  map<int, double, greater<int>> poly;
  for(int t=1; t<=2; t++) {
    int k;
    cin >> k;
    while (k--) {
      int exp;
      double coeff;
      cin >> exp >> coeff;
      if (poly.find(exp) != poly.end()) {
        poly[exp] += coeff;
        if(poly[exp] < eps) poly.erase(exp);
      }
      else poly[exp] = coeff;
    }
  }
  cout << poly.size();
  cout << fixed << setprecision(1);
  for (auto i=poly.begin(); i!=poly.end(); i++)
    cout << ' ' << i->first << ' ' << i->second;
}