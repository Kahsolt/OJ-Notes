#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#include <time.h>
#define N 100   // vertex num of set 0
#define M 100   // vertex num of set 1

// 2018/08/16
// 求解二分图匹配 hungary: O(n*m)
// 
// 边独立集(aka. 匹配)：任意边不相邻、没有公共顶点
// 边覆盖集：这些边可覆盖所有顶点
//   最大边独立数 + 最小边覆盖数 = n(顶点数)
//   一般地：最大匹配 + 1 <= 最小覆盖
//

int n, m;       // NOTE: assume n<=m
bool map[N][M]; // all linkage egde <n, m>
bool chk[N+M];  // mark visit in each iteration
int match[M];   // record the matching pair <m, n>

bool dfs(int p) { // find match for p of minor set
  for (int i=0; i<m; i++) // foreach m in major set, consider availablility
    if (!chk[i] && map[p][i]) {
      chk[i] = true;
      int t = match[i];     // save the original match of vertex-i
      match[i] = p;         // try change it to p
      if (t==-1 || dfs(t))  // if originally no match or can find match for the replacement of 't'
        return true;
      match[i] = t;         // restore original match on failure
    }
  return false;
}
int hungary(int n) {  // wrapper for dfs()
  memset(match, 0xFF, sizeof(match));
  int ans = 0;
  for (int i=0; i<n; i++) { // foreach n in minor set, try find matching m
    memset(chk, false, sizeof(chk));
    ans += dfs(i);    // true==1
  }
  return ans;
}

int main() {
  n = 4, m = 5;
  int set1[] = {1, 2, 3, 4};
  int set2[] = {5, 6, 7, 8, 9};

}