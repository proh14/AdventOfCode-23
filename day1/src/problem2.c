#define _GNU_SOURCE

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *nums[] = {"one", "two",   "three", "four", "five",
                      "six", "seven", "eight", "nine"};

int findDigitFromWord(char *word) {
  for (int i = 0; i < 9; i++) {
    if (strncmp(nums[i], word, strlen(nums[i])) == 0) {
      return i + 1;
    }
  }
  return -1;
}

int findFirstDigit(char *s, int len) {
  int i;
  for (i = 0; i < len; i++) {
    if (isdigit(s[i])) {
      return s[i] - '0';
    }
    int n = findDigitFromWord(&s[i]);
    if (n != -1) {
      return n;
    }
  }
  return -1;
}

int findLastDigit(char *s, int len) {
  int i;
  int max = -1;
  int rv = -1;
  for (i = 0; i < len; i++) {
    if (isdigit(s[i]) && i > max) {
      rv = s[i] - '0';
      max = i;
      continue;
    }
    int n = findDigitFromWord(&s[i]);
    if (n != -1 && i > max) {
      max = i;
      rv = n;
    }
  }
  return rv;
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
