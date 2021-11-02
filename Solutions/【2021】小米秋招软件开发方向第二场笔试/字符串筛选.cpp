#include <iostream>
#include <set>
using namespace std;

// 2021/08/09 

class Solution {
public:
  string unique_string(string s) {
    int slen = s.length();
    if (!slen) return s;

    cout << s << endl;

    set<char> F;
    char *tmp = new char[slen];
    int idx = 0;

    for (int i=0; i<slen; i++) {
      if (!F.count(s[i])) {
        tmp[idx++] = s[i];
        F.insert(s[i]);
      }
    }
    tmp[idx] = '\0';

    return string(tmp);
  }
};

int main() {
  Solution solut;
  cout << solut.unique_string("aab") << endl;
  cout << solut.unique_string("hellowelcometoxiaomi") << endl;
}
