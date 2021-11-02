// 2021/07/02
// NOTE: 注意字符串长度和指针位置差有个offset=1 ，以及手动补 '\0'

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* replaceSpace(char* s) {
    int cnt = 0, len = -1;
    char *p = s, *q, *t;
    while (*p) if (*p++ == ' ') cnt++;
    if (!cnt) return s;
    
    len += p - s;
    t = (char *)malloc((len + cnt * 2 + 1) * sizeof(char));
    p = s, q = t;
    while (*p) {
        if (*p != ' ')
            *q++ = *p;
        else {
            *q++ = '%';
            *q++ = '2';
            *q++ = '0';
        }
        p++;
    }
    *q = '\0';
    //free(s);
    return t;
}

int main() {
  char s[] = "We Are Happy";
  printf("%s\n", s);
  char *r = replaceSpace(s); 
  printf("%s\n", r);
}
