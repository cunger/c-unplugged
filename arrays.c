#include <stdio.h>

int * max(int * begin, int * end);

int main() {

  /* Syntax for creating a local array on the stack, where it is allocated
     one fixed-size block of memory: */

  int array1[]  = { 1 }; // { 1 }
  int array2[4] = { 1 }; // { 1, 0, 0, 0 }

  int numbers[3] = { 200, 404, 500 };

  /* Importantly, array size on the stack is fixed at compile time.

     Allocating memory for an array on the heap, on the other hand,
     allows for the size to be define at run time, when the array
     is created. */

  int *numbers_alternative;
  numbers_alternative = (int*) malloc(sizeof(int) * 3);

  /* numbers_alternative can now be used exactly like numbers. */

  free(numbers_alternative);

  /* Dynamically re-sizing an array requires explicit effort in re-allocating
     memory (where realloc takes care of copying over the old elements). */

     numbers_alternative = realloc(numbers_alternative, sizeof(int) * 10);

  /* Also, arrays are mainly pointers to the base address, they don't
     carry runtime information, so there's no way to get the length of an
     array at runtime; it needs to be determined at compile time:

     sizeof(numbers) = 3 times 4 bytes for an integer = 12
   */

  int length = sizeof(numbers) / sizeof(int); // 3

  /* Pointers */

  int * first = numbers; // points to the beginning of the array, i.e. *first == numbers[0]
  int * last = first + length - 1;

  printf("%d\n", *first);   // 200
  printf("%d\n", *numbers); // 200
  printf("%d\n", *last);    // 500

  /* Note that nothing will tell you when you're beyond the end of an array. */

  /* Passing an array to a function needs to happen by passing a pointer
     to the first element, and either the length of the array or a pointer
     to the end (usually a half-open range, i.e. the end being one element
     beyond the array). */

  int * largest = max(numbers, numbers + length);

  if (largest) {
    printf("%p -> %d\n", largest, *largest);
  }

  /* Note that empty arrays don't have any first element. */

  int * empty[0] = {};

  printf("%p\n",  empty);    // 0x7fff34ee4c68
  printf("%p\n", *empty);    // (nil)
  printf("%p\n",  empty[0]); // (nil)
  // **empty; => segmentation fault (core dumped)

  int * no_largest = max(*empty, *empty);

  if (no_largest) {
    printf("Hö?\n");
  } else {
    printf("Ha.\n");
  }

  return 0;
}

int * max(int * begin, int * end) {
  if (begin == end) return 0;

  int * max = begin;

  for (int * p = begin; p != end; ++p) {
    if (*p > *max) max = p;
  }

  return max;
}
