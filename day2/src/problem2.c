#define _GNU_SOURCE

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fill(char *str, int size, int rgb[]) {
  str[strlen(str) - 1] = '\0';

  if (strcmp(str, "red") == 0 && rgb[0] < size) {
    rgb[0] = size;
    return;
  }

  if (strcmp(str, "green") == 0 && rgb[1] < size) {
    rgb[1] = size;
    return;
  }

  if (strcmp(str, "blue") == 0 && rgb[2] < size) {
    rgb[2] = size;
  }
}

int findPower(char *s) {
  char *t1 = NULL;
  char *t2 = NULL;
  int rgb[3] = {0};
  strtok(s, " ");
  strtok(NULL, ":");
  while ((t1 = strtok(NULL, " ")) != NULL && (t2 = strtok(NULL, " ")) != NULL) {
    fill(t2, atoi(t1), rgb);
  }
  return rgb[0] * rgb[1] * rgb[2];
}

int main() {
  FILE *fp = fopen("../res/input.txt", "r");
  if (fp == NULL) {
    perror("Error: can't open the file");
    return 1;
  }
  size_t size = 0;
  int len = 0, sum = 0;
  char *s = NULL;

  while ((len = getline(&s, &size, fp)) != -1) {
    sum += findPower(s);
  }

  printf("Sum of valid ids: %d\n", sum);
  fclose(fp);
  return 0;
}
