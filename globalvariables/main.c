#include <stdio.h>

// The following function declarations should be in a header file.
int get_apples();
int get_oranges();
void set_apples(int);
void set_oranges(int);

int main() {
  set_apples(2);
  set_oranges(3);

  printf("apples: %d, oranges: %d\n", get_apples(), get_oranges());

  return 0;
}
