#include <stdio.h>
#include <string.h>
#define NSTR 81

int main() {
  char text[NSTR]; scanf("%s", text);
  size_t len = strlen(text);
  int height = (len + 2) / 3 - 1;
  int width = len - 2 * height;
  int gap = width - 2;
  char* begin = text;
  char* end = text + len - 1;

  while (height--) {
    putchar(*begin);
    for (int i=1; i<=gap; i++)
      putchar(' ');
    putchar(*end); putchar(10);
    begin++; end--;
  }
  while (begin != end + 1)
    putchar(*begin++);
}