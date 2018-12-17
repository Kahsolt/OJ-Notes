#include <iostream>
#include <iomanip>
#include <map>
#define esp 1e-5
using namespace std;
// Product of Polynomials (25)

int main() {
  map<int, double, greater<int>> poly[3];
  for (int t=0; t<2; t++) {
    int n;
    cin >> n;
    while (n--) {
      int exp;
      double coeff;
      cin >> exp >> coeff;
      if (poly[t].find(exp) != poly[t].end())
        poly[t][exp] += coeff;
      else poly[t][exp] = coeff;
    }
  }
  for (auto p1=poly[0].begin(); p1!=poly[0].end(); p1++)
    for (auto p2=poly[1].begin(); p2!=poly[1].end(); p2++) {
      int k = p1->first + p2->first;
      if (poly[2].find(k) != poly[2].end())
        poly[2][k] += p1->second * p2->second;
      else
        poly[2][k] = p1->second * p2->second;
      if (poly[2][k] < esp)   // clear when coeff ~= 0.0
        poly[2].erase(k);
    }
  cout << poly[2].size();
  cout << fixed << setprecision(1);
  for (auto p=poly[2].begin(); p!=poly[2].end(); p++)
    cout << ' ' << p->first << ' ' << p->second;
  cout << endl;
}
