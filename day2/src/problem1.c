#define _GNU_SOURCE

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool check(char *str, int size) {
  const int R_MAX = 12;
  const int G_MAX = 13;
  const int B_MAX = 14;

  if ((strcmp(str, "red\n") == 0 || strcmp(str, "red,") == 0 ||
       strcmp(str, "red;") == 0) &&
      size <= R_MAX) {
    return true;
  }

  if ((strcmp(str, "green\n") == 0 || strcmp(str, "green,") == 0 ||
       strcmp(str, "green;") == 0) &&
      size <= G_MAX) {
    return true;
  }

  if ((strcmp(str, "blue\n") == 0 || strcmp(str, "blue,") == 0 ||
       strcmp(str, "blue;") == 0) &&
      size <= B_MAX) {
    return true;
  }

  return false;
}

int isValid(char *s) {
  int id = 0;
  char *t1 = NULL;
  char *t2 = NULL;
  strtok(s, " ");
  id = atoi(strtok(NULL, ":"));
  while ((t1 = strtok(NULL, " ")) != NULL && (t2 = strtok(NULL, " ")) != NULL) {
    if (!check(t2, atoi(t1))) {
      return 0;
    }
  }
  return id;
}

int main() {
  FILE *fp = fopen("../res/input.txt", "r");
  size_t size = 0;
  int len = 0, sum = 0;
  char *s = NULL;

  while ((len = getline(&s, &size, fp)) != -1) {
    sum += isValid(s);
  }

  printf("Sum of valid ids: %d\n", sum);
  fclose(fp);
  return 0;
}
