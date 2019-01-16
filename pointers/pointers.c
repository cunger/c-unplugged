#include <stdio.h>

int main() {
  char whoop = 'y';
  char * p = &whoop;

  if (p) { printf("%d\n", *p); }

  // Function pointers

  return 0;
}
