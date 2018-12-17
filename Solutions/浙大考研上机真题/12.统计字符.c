#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
  char def[6], txt[81];
  bool reg[1<<7];  // register to count
  int cnt[1<<7];   // counter
  
  while (true) {
    memset(reg, false, sizeof(reg));
    memset(cnt, 0x00, sizeof(cnt));
    
    if (!gets(def)|| !strcmp(def, "#")) break;
    
    char *p = def; while (*p != '\0')
      reg[*p++] = true;

    gets(txt); p = txt;
    while (*p != '\0') {
      if (reg[*p]) cnt[*p]++;
      p++;
    }

    p = def; while (*p != '\0') {
      printf("%c %d\n", *p, cnt[*p]);
      p++;
    }
  }
}