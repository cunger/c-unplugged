#include <stdio.h>

int main() {
  int start;

  start = 0;
  int before = start++;

  start = 0;
  int after = ++start;

  printf("before = %d, after = %d\n", before, after);

  return 0;
}
