#include <iostream>
#include <set>
using namespace std;
#define M 10000

// Vertex Cover (25)

typedef struct edge {
  int from, to;
} Edge;
Edge edges[M];

int main() {
  cin.sync_with_stdio(false);

  int n, m; cin >> n >> m;
  for (int i=0; i<m; i++)
    cin >> edges[i].from >> edges[i].to;
  int k; cin >> k;
  while (k--) {
    int vcnt; cin >> vcnt;
    set<int> vex;
    while (vcnt--) {
      int v; cin >> v;
      vex.insert(v);
    }
    bool ok = true;
    for (int i=0; ok && i<m; i++)
      if (vex.find(edges[i].from) == vex.end()
          && vex.find(edges[i].to) == vex.end())
        ok = false;
    cout << (ok ? "Yes" : "No") << endl;
  }
}