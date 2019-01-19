#include <stdio.h>


int main() {
  int x = 23;

  /* Pointer to the addressof a variable */

  printf("memory address of x: %p\n", &x);

  int * p = &x;

  /* Dereferencing a pointer, getting the value at that address */

  int y = *p;

  printf("memory address of y: %p\n", &y);

  printf("*p = %d\n", *p);
  printf(" y = %d\n", y);

  /* Changing the value at the address of a variable
     effectively changes the value of the variable. */

  *p = 47;

  printf(" x = %d\n", x);
  printf(" y = %d\n", y);

  /* When declaration a pointer, initialize it to 0,
     which is an invalid address. */

  int * null_pointer = 0;

  char whoop = 'y';
  char * wp = &whoop;

  if (wp) { printf("%c\n", *wp); }

  // Function pointers

  return 0;
}
