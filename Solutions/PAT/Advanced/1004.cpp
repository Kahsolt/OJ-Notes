#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#define N 100
using namespace std;
// Counting Leaves (30)

int father[N];        // father[i]: father id of node-i
vector<int> sons[N];  // son[i]: son ids of node-i
void toposort(int n) {
  int queue[N], head = 0, rear = 0;
  for (int i=1; i<=n; i++)
    if (!~father[i]) {  // found root
      queue[head] = i;
      head = (head + 1) % N;
      break;  // should be unique
    }
  int robin = head;   // robin is the watershed of layer

  bool first = true;
  while (head != rear) {
    int cnt = 0;
    while (rear != robin) { // solve until robin met
      int n = queue[rear];
      rear = (rear + 1) % N;
      if (sons[n].size() == 0) cnt++;
      else for (auto it=sons[n].begin(); it!=sons[n].end(); it++) {
        queue[head] = *it;
        head = (head + 1) % N;
      }
    }
    robin = head;
    if (first) { printf("%d", cnt); first = false;}
    else printf(" %d", cnt);
  }
}

int main() {
  memset(father, 0xFF, sizeof(father)); // default -1, no father
  int n, m;
  cin >> n >> m;
  for (int i=1; i<=m; i++) {
    int f, k;   // father id & son count
    cin >> f >> k;
    while (k--) {
      int s;    // son id
      cin >> s;
      sons[f].push_back(s);
      father[s] = f;
    }
  }
  toposort(n);
}