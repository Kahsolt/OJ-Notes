#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
#define N 300000

// 2021/08/09

/* test data
5
1 2 3 3 5
3
1 2 1
2 4 5
3 5 3
*/

int x[N+1];
set<int> s;

struct Node {
  int l, r;            // range [l, r]
  Node *left, *right;
  map<int, int> cnt;   // cnt of k in this tree
  Node(int L, int R) : l(L), r(R), left(nullptr), right(nullptr) { }
};

Node* build(int L, int R) {
  cout << "build [" << L << ", " << R << "]" << endl;

  Node *r = new Node(L, R);
  if (L < R) {
    int M = (L + R) >> 1;
    r->left = build(L, M);
    r->right = build(M+1, R);
  }

  if (L == R) {
    r->cnt[x[L]] = 1;
  } else {
    for (auto it=s.begin(); it!=s.end(); it++)
      r->cnt[*it] = r->left->cnt[*it] + r->right->cnt[*it];
  }

  return r;
}

void visit(Node *root, int depth) {
  if (root->left) visit(root->left, depth+1);
  
  for (int i=0; i<depth; i++) cout << "  ";
  cout << "[" << root->l << ", " << root->r << "] k={";
  for (auto it=s.begin(); it!=s.end(); it++)
    cout << *it << ":" << root->cnt[*it] << ", ";
  cout << "}" << endl;
  
  if (root->right) visit(root->right, depth+1);
}

int query(Node *root, int l, int r, int k) {
  if (root->l == l && root -> r == r)
    return root->cnt[k];
  
  if (root->left && root->left->l <= l && r <= root->left->r)
    return query(root->left, l, r, k);
  if (root->right && root->right->l <= l && r <= root->right->r)
    return query(root->right, l, r, k);

  return query(root->left, l, root->left->r, k) 
         + query(root->right, root->right->l, r, k);
}

int main() {
  cin.sync_with_stdio(false);

  int n; cin >> n;
  for (int i=1; i<=n; i++) {
    cin >> x[i];
    s.insert(x[i]);
  }
  Node *root = build(1, n);
  visit(root, 0);

  int q; cin >> q;
  for (int i=1; i<=q; i++) {
    int l, r, k; cin >> l >> r >> k;
    if (l < 1 || r > n) cout << 0 << endl;    // illeagal
    else cout << query(root, l, r, k) << endl;
  }
}

/* accsum方法, MLT
int main() {
  cin.sync_with_stdio(false);

  int n; cin >> n;
  set<int> s;
  for (int i=1; i<=n; i++) {
    cin >> x[i];
    s.insert(x[i]);
  }
  
  map<int, vector<int>> m;
  for (auto it=s.begin(); it!=s.end(); it++) {
    vector<int> accsum;     // accsum[i]: x[1:i](含端点)之间有多少k
    accsum.push_back(0);    // dummy
    int cnt = 0;
    for (int i=1; i<=n; i++) {
      cnt += x[i] == *it;
      accsum.push_back(cnt);
    }
    m[*it] = accsum;
  }

  int q; cin >> q;
  for (int i=1; i<=q; i++) {
    int l, r, k; cin >> l >> r >> k;
    cout << ((l > r || s.find(k) == s.end())
            ? 0
            : (m[k][r] -  m[k][l-1]))
         << endl;
  }
}
*/