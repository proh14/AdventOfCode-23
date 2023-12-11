#define _GNU_SOURCE

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int findFirstDigit(char *s, int len) {
  int i;
  for (i = 0; i < len; i++) {
    if (isdigit(s[i])) {
      return s[i] - '0';
    }
  }
  return -1;
}

int findLastDigit(char *s, int len) {
  int i;
  int max = -1;
  for (i = 0; i < len; i++) {
    if (isdigit(s[i]) && i > max) {
      max = i;
    }
  }
  return s[max] - '0';
}

int main() {
  FILE *fp = fopen("../res/input.txt", "r");
  int sum = 0, len = 0;
  size_t size = 0;
  char *s;

  while ((len = getline(&s, &size, fp)) != -1) {
    int firstDigit = findFirstDigit(s, len);

    int lastDigit = findLastDigit(s, len);
    sum += firstDigit * 10 + lastDigit;
  }

  printf("sum = %d\n", sum);
  free(s);
  fclose(fp);
  return 0;
}
