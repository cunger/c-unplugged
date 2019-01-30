#include <stdio.h>


int main() {
  int x = 23;

  /* Pointer to the addressof a variable */

  printf("memory address of x: %p\n", &x);

  int * p = &x;

  /* Note that a pointer MUST be initialized to point to something.
     For example:

     int * p;
     *p = 47;

     In this case, the first statement allocates memory for the pointer,
     but nothing else. In particular, p does NOT point to anything.
     So the second statement just overwrites a random area in memory.
     Instead:

     int * p; // allocate pointer
     int i;   // allocate pointee

     p = &i;  // setup pointer to point to pointee
     *p = 47; // fine
     */

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

  /* When declaring a pointer without a particular value to point at,
     initialize it to 0, which is an invalid address. */

  int * null_pointer = 0;
  int * the_same = NULL;

  /* The constant NULL is defined to be 0, thus a NULL pointer will
     behave like a boolean false when used in a boolean context. */

  /* Safe guard: When using a pointer, first check whether it's valid. */

  if (null_pointer) { printf("%d\n", *null_pointer); }

  /* TODO Function pointers */

  return 0;
}
