#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define D

char cipher[95];
char box[95];
FILE *fin, *fout;

void get_cipher() {
  char mark[95], tmp[33], *p, *q;
  int i;

  memset(cipher, 0, sizeof(cipher));
  memset(mark, 0, sizeof(mark));
  p = gets(tmp);
  q = cipher;
  while(*p != '\0') {
    if(! mark[*p - 32]) {
      mark[*p - 32] = 1;
      *q++ = *p;
    }
    p++;
  }
  for(i = 0;i <= 94; i++)
    if(!mark[i]) *q++ = i + 32;
  
#ifdef D
  printf("cipher = %s\n", cipher);  /* MAYBE DANGEROUS */
#endif
}

void get_box() {
  int n = 94, i;
  char next[95], first = cipher[0], idx = 0, last = 94;
  
  for(i=0; i <= 93; i++) next[i] = i + 1; next[i] = 0;
  memset(box, 0, sizeof(box));

  int text;
  while(n--) {
    int cnt = cipher[idx];
    text = cnt;
    next[last] = next[idx]; /* skip cur idx */
    while(cnt--) {
      last = idx;
      idx = next[idx];
    }
    box[text - 32] = cipher[idx];
  }
  box[text - 32] = cipher[first];
}
void do_encrypt() {
  fin = fopen("in.txt", "r");
  fout = fopen("in_crpyt.txt", "w");  /* 官方拼错文件名系列.jpg */

  int c;
  while((c = fgetc(fin)) != EOF) {
    if(c == '\n') fputc('\n', fout);
    else fputc(box[c - 32], fout);
  }

  fflush(fout);
}

int main() {
  get_cipher();
  get_box();
  do_encrypt();

  return 0;
}
