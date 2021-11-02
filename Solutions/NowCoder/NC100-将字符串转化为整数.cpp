// 2021/08/11 
// Note: 

#define ERROR throw "Error"

static inline bool isdigit(char c) { return '0' <= c && c <= '9'; }
static inline int c2i(char c) { return c - '0'; }

class Solution {
public:
  int atoi(const char *str) {
    try {
      if (!str) ERROR;
      int len = strlen(str);
      if (!len) ERROR;

      bool neg = false;
      const char *p = str;
      int res = 0;
      if (*p == '-') { neg = true; p++; }
      else if (*p == '+') p++;
      while (*p) {
        if (!isdigit(*p)) ERROR;
        res = res * 10 + c2i(*p);
        p++;
      }
      return neg ? -res : res;
    } catch (...) {
      return 0;
    }
  }
};
