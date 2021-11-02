// 2021/08/08 
// Note: 位向量记录，但数据上不如排序后直接遍历……

static const int MAX_N = 100000000;
static int bv[MAX_N/32+1];

inline void setb(int i) { bv[i/32] |= (0x01 << (i % 32)); }
inline int getb(int i) { return (bv[i/32] >> (i % 32)) & 0x01; }

int MLS(int* arr, int arrLen) {
  memset(bv, 0x00, sizeof(bv));

  for (int i=0; i<arrLen; i++)
    setb(arr[i]);

  int len = 1, maxlen = 1;
  for (int i=2; i<MAX_N; i++)
    if (getb(i)) {
      if (getb(i-1)) len++;
    } else {
      if (len > maxlen) {
        maxlen = len;
        if (maxlen > MAX_N - i) break;  // stop early
      }
      len = 1;
    }
  
  return maxlen;
}
