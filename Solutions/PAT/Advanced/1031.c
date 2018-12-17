#include <stdio.h>
#include <string.h>
#define N 81
/* Hello World for U (20) */

int main() {
  char text[N];
  scanf("%s", text);
  size_t len = strlen(text);
  unsigned char height = (len + 2) / 3 - 1;
  unsigned char width = len - 2 * height;
  unsigned char gap = width - 2;
  char* begin = text;
  char* end = text + len - 1;

  while (height--) {
    printf("%c", *begin);
    for (int i=1; i<=gap; i++)
      printf(" ");
    printf("%c\n", *end);
    begin++; end--;
  }
  while (begin != end + 1) {
    printf("%c", *begin);
    begin++;
  }
}