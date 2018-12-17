#include <iostream>
#include <iomanip>
using namespace std;
// A+B Format (20)

void prt(int x) {
  int low = x % 1000;
  x /= 1000;
  if (x) {
    prt(x);
    cout << ',' << setw(3) << setfill('0') << low;
  } 
  else cout << low;
}
int main() {
  int a,b;
  cin >> a >> b;
  a += b;
  if (a < 0) { cout << '-'; a = -a; }
  prt(a);
  cout << endl;
  return 0;
}