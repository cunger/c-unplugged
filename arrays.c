#include <stdio.h>

int main() {
  int array[5] = { 10, 20, 30, 40, 50 };
  // array[0] = 10;
  // array[1] = 20;

  int * first = &array[0]; // first = pointer to the address of the first element
  int * last  = &array[4];

  printf("first:  %d\n", *first); // *first = value stored at address first
  printf("last:   %d\n", *last);

  ++first; // pointing to next

  printf("next:   %d\n", *first);

  first += 3; // pointing to last
  // Note that you can easily move a pointer beyond the end of the array
  // without noticing or C telling you.

  printf("next+3: %d\n", *first);

  char buffer[1024] = { 0 };

  return 0;
}
