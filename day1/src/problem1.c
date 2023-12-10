#define _GNU_SOURCE

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp = fopen("../res/input.txt", "r");
  int n = 0, sum = 0;
  size_t size = 0;
  char *s;
  int len;
  int i;
  int max = 0;
  while ((len = getline(&s, &size, fp)) != -1) {
    for (i = 0; i < len; i++) {
      if (isdigit(s[i])) {
        n = n * 10 + (s[i] - '0');
        break;
      }
    }
    for (; i < len; i++) {
      if (isdigit(s[i])) {
        if (i > max) {
          max = i;
        }
      }
    }
    n = n * 10 + (s[max] - '0');
    sum += n;
    n = 0;
    max = 0;
  }

  printf("sum = %d\n", sum);
  fclose(fp);
  return 0;
}
