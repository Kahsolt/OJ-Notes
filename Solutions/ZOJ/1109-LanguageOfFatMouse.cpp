#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#define NCHAR 11
using namespace std;

int main() {
  map<string, string> dict;
  char s[NCHAR], e[NCHAR];

  while (true) {
    if (!scanf("%[^ \n]s", s)) break;
    getchar(); scanf("%[^\n]s", e); getchar();
    dict[string(e)] = string(s);
  }
  getchar();
  while (~scanf("%[^\n]s", e)) {
    getchar();
    string ans = "eh";
    if (dict[string(e)] != "") ans = dict[string(e)];
    cout << ans << endl;
  } 
}