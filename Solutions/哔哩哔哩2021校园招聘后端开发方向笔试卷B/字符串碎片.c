// 2021/08/15 

int GetFragment(char* p) {
  if (!p) return 0;
  int len = strlen(p);
  if (!len) return 0;

  char last = *p++;
  int segs = 1;
  while (*p) {
    if (*p != last) {
      last = *p;
      segs++;
    }
    p++;
  }
  return len / segs;
}