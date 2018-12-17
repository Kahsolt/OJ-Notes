#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

typedef struct foo {
  int w, v;
  bool operator< (foo &f) { // C++ support
    return w != f.w ? w < f.w : v < f.v;	// w has priority
  }
} Foo;

int main() {
  srand(time(NULL));
  
  int n = 10;
  Foo foos[10];
  for (int i=0; i<n; i++) {
    foos[i].w = rand() % 4;
    foos[i].v = rand() % 20;
    cout << foos[i].w << ':' << foos[i].v << endl;
  }
  cout << endl;

  sort(foos, foos+n);
  for (int i=0; i<n; i++)
    cout << foos[i].w << ':' << foos[i].v << endl;
}
